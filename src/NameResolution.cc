#include "NameResolution.h"
#include <iostream>
#include <assert.h>
#include <set>

using namespace std;

void EnvironmentVisitor::visit(ClassDeclaration& node) 
{
    assert(environments.size() == 1);

    const std::string& class_name = package + "." + node.name->getString();
    if(environments.top()->classes.find(class_name) != environments.top()->classes.end() &&
       environments.top()->interfaces.find(class_name) != environments.top()->interfaces.end())
    {
        cout << "Redefinition of class/interface " << class_name << endl;
        exit(42);
    }
    else
    {
        environments.top()->classes[class_name] = &node;
    }
    environments.push(&node.environment); 
}

void EnvironmentVisitor::visit(InterfaceDeclaration& node) 
{ 
    assert(environments.size() == 1);

    const std::string& interface_name = package + "." + node.name->getString();
    if(environments.top()->classes.find(interface_name) != environments.top()->classes.end() &&
       environments.top()->interfaces.find(interface_name) != environments.top()->interfaces.end())
    {
        cout << "Redefinition of class/interface " << interface_name << endl;
        exit(42);
    }
    else
    {
        environments.top()->interfaces[interface_name] = &node;
    }
    environments.push(&node.environment); 
}

void EnvironmentVisitor::visit(MethodDeclaration& node) 
{
    environments.top()->methods[node.name->getString()] = &node;
    environments.push(&node.environment); 
}

void EnvironmentVisitor::visit(Block& node) 
{ 
    environments.push(&node.environment); 
}

void EnvironmentVisitor::visit(FormalParameter& node) 
{
    environments.top()->formal_params[node.id->getString()] = &node;
}

void EnvironmentVisitor::visit(VariableDeclarationExpression& node) 
{  
    const std::string& name = node.name->getString();
    if(environments.top()->classes.find(name) != environments.top()->classes.end())
    {
        cout << "Redefinition of local variable " << name << endl;
        exit(42);
    }
    else
    {
        environments.top()->variables[name] = &node;
    }
}

void EnvironmentVisitor::visit(FieldDeclaration& node) 
{  
    const std::string& name = node.declaration->name->id;
    if(environments.top()->classes.find(name) != environments.top()->classes.end())
    {
        cout << "Redefinition of field " << name << endl;
        exit(42);
    }
    else
    {
        environments.top()->fields[name] = &node;
    }
}

void EnvironmentVisitor::visit(CompilerUnit& node)
{
    if(node.packageDecl)
    {
        package = node.packageDecl->name->getString();
    }
    else // Reset package name if a package declaration DNE
    {
        package = UNNAMED_PACKAGE;
    }

    environments = std::stack<Environment*>();
    environments.push(&global);
}

void EnvironmentVisitor::leave(ClassDeclaration& node) { environments.pop(); }
void EnvironmentVisitor::leave(InterfaceDeclaration& node) { environments.pop(); }
void EnvironmentVisitor::leave(MethodDeclaration& node) { environments.pop(); }
void EnvironmentVisitor::leave(Block& node) { environments.pop(); }

void TypeLinkingVisitor::visit(QualifiedType& node)
{
    ASTNodeVisitor::visit(dynamic_cast<Type&>(node));

    std::string type_name;

    type_name = node.name->getString();

    if(dynamic_cast<QualifiedName*>(node.name))
    {
        if(global->classes.find(type_name) != global->classes.end())
        {
            node.name->refers_to = global->classes[type_name];
        }
        else if(global->interfaces.find(type_name) != global->interfaces.end())
        {
            node.name->refers_to = global->interfaces[type_name];
        }
        else
        {
            std::cout << "Undefined qualified type name \"" << type_name << "\" used";
            exit(42);
        }

        // When a fully qualified name resolves to a type, no strict prefix of the fully qualified name can resolve to a type in the same environment.
        // Iterate over every prefix

        // Get current environment
        ASTNode* parent = node.parent;
        Environment* current_env;
        while(!parent->getEnvironment())
        {
            parent = parent->parent;
        }
        current_env = parent->getEnvironment();
        assert(current_env);

        std::string prefix = type_name;
        size_t last_period = type_name.find_last_of('.');
        while(last_period != std::string::npos)
        {
            prefix = prefix.substr(0, last_period);
            last_period = prefix.find_last_of('.');

            if(current_env->classes.find(prefix) != current_env->classes.end() ||
               current_env->interfaces.find(prefix) != current_env->interfaces.end())
               {
                    std::cout << "Strict prefix of fully qualified name " << type_name 
                    << " collides with type defined in the same scope" <<  std::endl;
                    exit(42);
               }
        }
    }
    else
    {
        // Enclosing class/interface
        ASTNode* parent = node.parent;

        while(parent)
        {
            if(dynamic_cast<ClassDeclaration*>(parent) &&
               dynamic_cast<ClassDeclaration*>(parent)->name->getString() == type_name)
            {
                node.name->refers_to = parent;
                return;
            }

            if(dynamic_cast<InterfaceDeclaration*>(parent) &&
               dynamic_cast<InterfaceDeclaration*>(parent)->name->getString() == type_name)
            {
                node.name->refers_to = parent;
                return;
            }
            
            parent = parent->parent;
        }

        // Single-type import
        parent = node.parent;

        while(parent)
        {
            // Find compiler unit that type is in
            if(dynamic_cast<CompilerUnit*>(parent))
            {
                ASTNodeList<ImportDeclaration>* imports = dynamic_cast<CompilerUnit*>(parent)->importDecls;
                // TypeDeclaration* current_package_decl = dynamic_cast<CompilerUnit*>(parent)->typeDecl;
                
                if(imports)
                {
                    // Scan through import statements
                    for(ImportDeclaration* import: imports->elements)
                    {
                        size_t last_delimiter = import->name->getString().find_last_of('.');
                        std::string single_type_name = import->name->getString().substr(last_delimiter + 1);

                        if(last_delimiter != std::string::npos && single_type_name == type_name)
                        {
                            std::string package_name = import->name->getString().substr(0, last_delimiter);

                            for(const ASTNode* ast: asts)
                            {
                                const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);

                                // If package name matches and the type is in the package
                                if(cunit->packageDecl && cunit->packageDecl->name->getString() == package_name && 
                                   cunit->typeDecl &&
                                   cunit->typeDecl->getName()->getString() == single_type_name)
                                {
                                    node.name->refers_to = cunit->typeDecl;
                                    return;
                                }
                            }

                            std::cout << "Import " << import->name->getString() << " does not exist" <<  std::endl;
                            exit(42);
                        } 
                    }
                }
            }
            
            parent = parent->parent;
        }

        // Type in same package
        parent = node.parent;

        while(parent)
        {
            // Find compiler unit that type is in
            if(dynamic_cast<CompilerUnit*>(parent))
            {
                PackageDeclaration* current_package_decl = dynamic_cast<CompilerUnit*>(parent)->packageDecl;

                std::string package_name = UNNAMED_PACKAGE;
                if(current_package_decl) package_name = current_package_decl->name->getString();

                if(type_name == "A") std::cout << "Current package: " << package_name << std::endl;
                if(type_name == "A") std::cout << "Current typename: " << type_name << std::endl;

                for(const ASTNode* ast: asts)
                {
                    std::string other_package_name = UNNAMED_PACKAGE;
                    const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);

                    if(cunit->packageDecl) other_package_name = cunit->packageDecl->name->getString();

                    if(type_name == "A") std::cout << "Other package: " << other_package_name << std::endl;
                    if(type_name == "A") std::cout << "Other typdef: " << cunit->typeDecl->getName()->getString() << std::endl;

                    // If package name matches and the type is in the package
                    if(package_name == other_package_name && 
                       cunit->typeDecl && 
                       cunit->typeDecl->getName()->getString() == type_name)
                    {
                        node.name->refers_to = cunit->typeDecl;
                        return;
                    }
                }
                
            }
            
            parent = parent->parent;
        }

        // Import-on-demand package
        // Nearly identical to "Single-type import" but kept seperate in case "Type in same package" needs additions
        parent = node.parent;

        while(parent)
        {
            // Find compiler unit that type is in
            if(dynamic_cast<CompilerUnit*>(parent))
            {
                ASTNodeList<ImportDeclaration>* imports = dynamic_cast<CompilerUnit*>(parent)->importDecls;
                
                if(imports)
                {
                    // Scan through import statements
                    for(ImportDeclaration* import: imports->elements)
                    {
                        size_t last_delimiter = import->name->getString().find_last_of('.');

                        // If the import is a declareAll import
                        if(import->declareAll)
                        {
                            std::string package_name = import->name->getString().substr(0, last_delimiter);

                            bool package_found = false;

                            // Search all packages with packge_name for the type
                            for(const ASTNode* ast: asts)
                            {
                                const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);

                                // If package name matches and the type is in the package
                                if(cunit->packageDecl && cunit->packageDecl->name->getString() == package_name)
                                {
                                    package_found = true;
                                    
                                    if(cunit->typeDecl &&
                                       cunit->typeDecl->getName()->getString() == node.name->getString())
                                    {
                                        node.name->refers_to = cunit->typeDecl;
                                        return;
                                    }
                                }
                            }

                            // Every import-on-demand declaration must refer to a package declared in some file listed on the Joos command line.
                            if(!package_found)
                            {
                                std::cout << "Import-on-demand package" << package_name << " does not exist" << std::endl;
                                exit(42);
                            }
                        }
                    }
                }
            }
            
            parent = parent->parent;
        }

        // All type names must resolve to some class or interface declared in some file listed on the Joos command line.
        std::cout << "Type name " << node.name->getString() << " does not exist" << std::endl;
        exit(42);
    }
}

void checkTypeLinking(Environment* global, std::vector<ASTNode*> asts)
{
    for(ASTNode* file_ast: asts)
    {
        assert(dynamic_cast<CompilerUnit*>(file_ast));

        ASTNodeList<ImportDeclaration>* imports = dynamic_cast<CompilerUnit*>(file_ast)->importDecls;
        TypeDeclaration* current_package_decl = dynamic_cast<CompilerUnit*>(file_ast)->typeDecl;
        PackageDeclaration* package_decl = dynamic_cast<CompilerUnit*>(file_ast)->packageDecl;

        std::vector<std::string> used_package_names;
        if(package_decl)
        {
            used_package_names.push_back(package_decl->name->getString());
        }
        
        if(imports)
        {
            std::set<std::string> single_type_imports;
            std::set<std::string> simple_types;

            // Scan through import statements
            for(ImportDeclaration* import: imports->elements)
            {
                size_t last_delimiter = import->name->getString().find_last_of('.');
                std::string single_type_name = import->name->getString().substr(last_delimiter + 1);

                if(last_delimiter != std::string::npos)
                {
                    used_package_names.push_back(import->name->getString().substr(0, last_delimiter));
                }

                // No single-type-import declaration clashes with the class or interface declared in the same file.
                if(single_type_name == current_package_decl->getName()->getString())
                {
                    std::cout << "Class/interface " << import->name->getString() << " redefined in file" <<  std::endl;
                    exit(42);
                }

                // No two single-type-import declarations clash with each other.
                if(single_type_imports.find(single_type_name) != single_type_imports.end())
                {
                    std::cout << "Single type import " << import->name->getString() << " already defined" <<  std::endl;
                    exit(42);
                }

                // All simple type names must resolve to a unique class or interface.
                {
                    if(simple_types.find(single_type_name) != simple_types.end())
                    {
                        std::cout << "Simple type name " << single_type_name << " redefined" <<  std::endl;
                        exit(42);
                    }

                    // If its an import-on-demand package, add its type decl to simple types and check for clash
                    if(import->declareAll)
                    {
                        std::string package_name = import->name->getString().substr(0, last_delimiter);

                        // Search all packages with packge_name
                        for(const ASTNode* ast: asts)
                        {
                            const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);

                            // If package name matches, add type decl to simple types
                            if(cunit->packageDecl && cunit->packageDecl->name->getString() == package_name)
                            {
                                if(simple_types.find(cunit->typeDecl->getName()->getString()) != simple_types.end())
                                {
                                    std::cout << "Simple type name " << cunit->typeDecl->getName()->getString() << " redefined" <<  std::endl;
                                    exit(42);
                                }
                                simple_types.insert(cunit->typeDecl->getName()->getString());
                            }
                        }
                    }
                }

                single_type_imports.insert(single_type_name);
                simple_types.insert(single_type_name);
            }
        }

        //No package names or prefixes of package names of declared packages, single-type-import declarations or 
        //import-on-demand declarations that are used may resolve to types, except for types in the default package.
        // TODO Check
        for(std::string package_name: used_package_names)
        {
            std::string prefix = package_name;
            size_t last_period = package_name.find_last_of('.');
            while(last_period != std::string::npos)
            {
                prefix = prefix.substr(0, last_period);
                last_period = prefix.find_last_of('.');

                if(global->classes.find(prefix) != global->classes.end() ||
                   global->interfaces.find(prefix) != global->interfaces.end())
                {
                        std::cout << "Prefix of " << package_name << " resolves with type" <<  std::endl;
                        exit(42);
                }
            }
        }
        
    }
}

Environment resolveNames(std::vector<ASTNode*> asts)
{
    EnvironmentVisitor env_visitor;
    for(ASTNode* ast: asts) ast->visitAll(env_visitor);

    checkTypeLinking(&env_visitor.global, asts);
    TypeLinkingVisitor type_visitor(&env_visitor.global, asts);
    for(ASTNode* ast: asts) ast->visitAll(type_visitor);
    return env_visitor.global;
}