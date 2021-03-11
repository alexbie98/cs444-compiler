#include "NameResolution.h"
#include <iostream>
#include <assert.h>
#include <set>
#include <algorithm>
#include "HierarchyCheck.h"

using namespace std;

void printCurrentTraversalState(ASTNode& node, std::stack<Environment*> environments)
{
    ASTNode* scanner = &node;
    while (scanner)
    {
        std::cout << scanner->toString() << std::endl;
        scanner = scanner->parent;
    }

    std::cout << "------------------" << std::endl;

    Environment* scanner2 = environments.top();
    while (scanner2 && scanner2->node)
    {
        std::cout << scanner2->node->toString() << std::endl;


        std::cout << "---" << std::endl;

        ASTNode* scanner3 = scanner2->node;
        while (scanner3)
        {
            std::cout << scanner3->toString() << endl;
            scanner3 = scanner3->parent;
        }

        std::cout << "---" << std::endl;



        // if(dynamic_cast<ClassDeclaration*>(scanner2->node))
        //     std::cout << dynamic_cast<ClassDeclaration*>(scanner2->node)->name->getString() << std::endl;
        scanner2 = scanner2->parent;
    }
}

void EnvironmentVisitor::initEnvironment(ASTNode* node)
{
    assert(node->getEnvironment());

    node->getEnvironment()->parent = environments.top();
    node->getEnvironment()->node = node;
    environments.push(node->getEnvironment()); 
}

void EnvironmentVisitor::visit(ClassDeclaration& node) 
{
    if (environments.size() != 1)
    {
        printCurrentTraversalState(node, environments);
    }

    assert(environments.size() == 1);

    const std::string& class_name = package + "." + node.name->getString();
    if(environments.top()->classes.find(class_name) != environments.top()->classes.end() ||
       environments.top()->interfaces.find(class_name) != environments.top()->interfaces.end())
    {
        cout << "Redefinition of class/interface " << class_name << endl;
        exit(42);
    }
    else
    {
        environments.top()->classes[class_name] = &node;
        node.fullyQualifiedName = class_name;
    }
    initEnvironment(&node);
}

// TODO Combine as TypeDecleration
void EnvironmentVisitor::visit(InterfaceDeclaration& node) 
{
    if (environments.size() != 1)
    {
        printCurrentTraversalState(node, environments);
    }

    assert(environments.size() == 1);

    const std::string& interface_name = package + "." + node.name->getString();
    if(environments.top()->classes.find(interface_name) != environments.top()->classes.end() ||
       environments.top()->interfaces.find(interface_name) != environments.top()->interfaces.end())
    {
        cout << "Redefinition of class/interface " << interface_name << endl;
        exit(42);
    }
    else
    {
        environments.top()->interfaces[interface_name] = &node;
        node.fullyQualifiedName = interface_name;
    }
    initEnvironment(&node);
}

void EnvironmentVisitor::visit(MethodDeclaration& node) 
{
    environments.top()->methods[node.name->getString()] = &node;
    initEnvironment(&node);
}

void EnvironmentVisitor::visit(ConstructorDeclaration& node) 
{
    initEnvironment(&node);
}

void EnvironmentVisitor::visit(Block& node) 
{ 
    initEnvironment(&node);
}

void EnvironmentVisitor::visit(FormalParameter& node) 
{
    // Nearly identical to EnvironmentVisitor::visit(VariableDeclarationExpression& node) 
    const std::string& name = node.id->getString();

    Environment* env = environments.top();

    while(env && !dynamic_cast<TypeDeclaration*>(env->node))
    {
        
        if(env->contains(name))
        {
            cout << "Redefinition of local variable " << name << endl;
            exit(42);
        }

        env = env->parent;
    }
    
    environments.top()->formal_params[node.id->getString()] = &node;
}

void EnvironmentVisitor::visit(VariableDeclarationExpression& node) 
{  
    const std::string& name = node.name->getString();

    // Check outter scopes for duplicates
    Environment* env = environments.top();
    while(env && !dynamic_cast<TypeDeclaration*>(env->node))
    {
        if(env->contains(name))
        {
            cout << "Redefinition of local variable (can only shadow fields)" << name << endl;
            exit(42);
        }

        env = env->parent;
    }
    
    environments.top()->variables[name] = &node;
}

void EnvironmentVisitor::visit(FieldDeclaration& node) 
{  
    const std::string& name = node.declaration->name->id;
    if(environments.top()->fields.find(name) != environments.top()->fields.end())
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
void EnvironmentVisitor::leave(ConstructorDeclaration& node) { environments.pop(); }
void EnvironmentVisitor::leave(Block& node) { environments.pop(); }

ASTNode* linkQualifedName(QualifiedName* node, Environment* global, std::string package_name, const std::vector<ASTNode*>& asts)
{
    ASTNode* result = nullptr;
    std::string type_name = node->getString();

    // TODO Fix imports occuring without import statements!
    if(global->classes.find(type_name) != global->classes.end())
    {
        result = global->classes[type_name];
    }
    else if(global->interfaces.find(type_name) != global->interfaces.end())
    {
        result = global->interfaces[type_name];
    }

    if(!result) return nullptr;

    // When a fully qualified name resolves to a type, no strict prefix of the fully qualified name can resolve to a type in the same environment.
    // (no prefixes (consisting of whole identifiers) of fully qualified types themselves resolve to types.)
    // Iterate over every prefix

    // Get current environment
    ASTNode* parent = node->parent->parent;
    Environment* current_env;
    while(!parent->getEnvironment())
    {
        parent = parent->parent;
    }
    current_env = parent->getEnvironment();
    assert(current_env);

    // Find all classes in current package
    // TODO Store this? Reused in "Type in same package"
    std::set<std::string> package_classes;

    for(const ASTNode* ast: asts)
    {
        const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);

        // If package name matches, add type decl to simple types
        if((cunit->packageDecl && cunit->packageDecl->name->getString() == package_name))
        {
            // TODO Can we have 0 typedecls in a file?
            package_classes.insert(cunit->typeDecl->getName()->getString()); 
        }
    }

    std::string prefix = type_name;
    size_t last_period = prefix.size();
    while(last_period != std::string::npos)
    {
        prefix = prefix.substr(0, last_period);
        last_period = prefix.find_last_of('.');

        // Either prefix is in another package, or inside the current package
        if(current_env->classes.find(prefix) != current_env->classes.end() ||
            current_env->interfaces.find(prefix) != current_env->interfaces.end() ||
            package_classes.find(prefix) != package_classes.end())
            {
                std::cout << "Strict prefix of fully qualified name " << type_name 
                << " collides with type defined in the same scope" <<  std::endl;
                exit(42);
            }
    }

    return result;
}

ASTNode* linkSimpleName(SimpleName* node, 
                        Environment* global, 
                        std::string package_name, 
                        const std::vector<ASTNode*>& asts,
                        CompilerUnit* ast_root,
                        ASTNodeList<ImportDeclaration>* imports)
{
    // Enclosing class/interface
    ASTNode* parent = node->parent;
    std::string type_name = node->getString();

    while(parent)
    {
        if(dynamic_cast<ClassDeclaration*>(parent) &&
            dynamic_cast<ClassDeclaration*>(parent)->name->getString() == type_name)
        {
            return parent;
        }

        if(dynamic_cast<InterfaceDeclaration*>(parent) &&
            dynamic_cast<InterfaceDeclaration*>(parent)->name->getString() == type_name)
        {
            return parent;
        }
        
        parent = parent->parent;
    }

    // Single-type import
    // Scan through import statements
    for(ImportDeclaration* import: imports->elements)
    {
        if(!import->declareAll)
        {
            size_t last_delimiter = import->name->getString().find_last_of('.');
            std::string single_type_name = import->name->getString().substr(last_delimiter + 1);
            assert(last_delimiter != std::string::npos);
            std::string import_package_name = import->name->getString().substr(0, last_delimiter);

            for(const ASTNode* ast: asts)
            {
                const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);

                // If package name matches and the type is in the package
                if(cunit->packageDecl->name->getString() == import_package_name && 
                    cunit->typeDecl &&
                    cunit->typeDecl->getName()->getString() == single_type_name)
                {
                    if(single_type_name == type_name)
                    {
                        return cunit->typeDecl;
                    }
                }
            }
        }
    }
    

    // Type in same package
    for(const ASTNode* ast: asts)
    {
        const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);
        std::string other_package_name = cunit->packageDecl->name->getString();

        // If package name matches and the type is in the package
        if(package_name == other_package_name && 
            cunit->typeDecl && 
            cunit->typeDecl->getName()->getString() == type_name)
        {
            return cunit->typeDecl;
        }
    }

    // Import-on-demand package

    // All simple type names must resolve to a unique class or interface.
    //      Ambiguity does not arise unless you try to use the simple type name
    //      (Could have both imports but only use qualifed names).
    //      Imports and packages don't cause ambiguities by themselves, instead
    //      the evaluation of a type in the file causes ambiguity.
    bool type_name_found = false;
    // Scan through import statements
    for(ImportDeclaration* import: imports->elements)
    {
        size_t last_delimiter = import->name->getString().find_last_of('.');

        // If its an import-on-demand package, add its type decl to simple types and check for clash
        if(import->declareAll)
        {
            std::string import_package_name = import->name->getString().substr(0, last_delimiter);

            // Search all packages with packge_name
            for(const ASTNode* ast: asts)
            {
                // Exclude current file
                if(ast != ast_root)
                {
                    const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);

                    // If package name matches, add type decl to simple types
                    if(cunit->packageDecl && cunit->packageDecl->name->getString() == import_package_name)
                    {
                        std::string simple_type_name = cunit->typeDecl->getName()->getString();

                        if(simple_type_name == type_name)
                        {
                            if(type_name_found)
                            {
                                std::cout << "Simple type name " << simple_type_name << " redefined" <<  std::endl;
                                exit(42);
                            }
                            type_name_found = true;
                        }
                    }
                }
            }
        }
    }

    // Import-on-demand package (contd...)

    // Scan through import statements
    for(ImportDeclaration* import: imports->elements)
    {
        size_t last_delimiter = import->name->getString().find_last_of('.');

        // If the import is a declareAll import
        if(import->declareAll)
        {
            std::string import_package_name = import->name->getString().substr(0, last_delimiter);

            // Search all packages with packge_name for the type
            for(const ASTNode* ast: asts)
            {
                // Exclude current file
                if(ast != ast_root)
                {
                    const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);
                    assert(cunit);

                    std::string other_package = cunit->packageDecl->name->getString();

                    // If package name matches and the type is in the package
                    if(cunit->packageDecl && import_package_name == other_package)
                    {
                        if(cunit->typeDecl &&
                            cunit->typeDecl->getName()->getString() == node->getString())
                        {
                            return cunit->typeDecl;
                        }
                    }
                }
            }
        }
    }

    return nullptr;
}

void TypeLinkingVisitor::visit(QualifiedType& node)
{
    ASTNodeVisitor::visit(dynamic_cast<Type&>(node));

    assert(node.name);
    std::string type_name = node.name->getString();

    if(dynamic_cast<QualifiedName*>(node.name))
    {
        node.name->refers_to = linkQualifedName(dynamic_cast<QualifiedName*>(node.name), global, package_name, asts);

        if(!node.name->refers_to)
        {
            std::cout << "Undefined qualified type name \"" << node.name->getString() << "\" used";
            exit(42);
        }
    }
    else
    {
        node.name->refers_to = linkSimpleName(dynamic_cast<SimpleName*>(node.name), global, package_name, asts, ast_root, imports);

        if(!node.name->refers_to)
        {
            // All type names must resolve to some class or interface declared in some file listed on the Joos command line.
            std::cout << "Type name " << node.name->getString() << " does not exist" << std::endl;
            exit(42);
        }
    }
}

void TypeLinkingVisitor::visit(CompilerUnit& node)
{
    assert(node.packageDecl);
    package_name = node.packageDecl->name->getString();
    ast_root = &node;
    imports = dynamic_cast<CompilerUnit*>(ast_root)->importDecls;
    assert(imports);
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

            // Scan through import statements
            for(ImportDeclaration* import: imports->elements)
            {
                size_t last_delimiter = import->name->getString().find_last_of('.');
                std::string single_type_name = import->name->getString().substr(last_delimiter + 1);
                std::string package_name = import->name->getString().substr(0, last_delimiter);

                if(last_delimiter != std::string::npos)
                {
                    used_package_names.push_back(import->name->getString().substr(0, last_delimiter));
                }
                else
                {
                    used_package_names.push_back(import->name->getString());
                }

                // No single-type-import declaration clashes with the class or interface declared in the same file.
                if(!import->declareAll && 
                   single_type_name == current_package_decl->getName()->getString() &&
                   (!package_decl || package_name != package_decl->name->getString())) // A class may import itself
                {
                    std::cout << "Class/interface " << import->name->getString() << " redefined in file" <<  std::endl;
                    exit(42);
                }

                // No two single-type-import declarations clash with each other.
                if(!import->declareAll && single_type_imports.find(single_type_name) != single_type_imports.end())
                {
                    std::cout << "Single type import " << import->name->getString() << " already defined" <<  std::endl;
                    exit(42);
                }

                // Check that all import-on-demand declarations refer to existing packages.
                if(import->declareAll)
                {
                    bool package_found = false;

                    // Search all packages with packge_name for the type
                    for(const ASTNode* ast: asts)
                    {
                        const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);
                        assert(cunit);
                        
                        // If package is prefix
                        std::string other_package = cunit->packageDecl->name->getString();

                        // If package name is a prefix and the type is in the package
                        auto res = std::mismatch(package_name.begin(), package_name.end(), other_package.begin());
                        if(cunit->packageDecl && res.first == package_name.end() && 
                           (other_package.size() == package_name.size() || other_package[package_name.size()] == '.')) // package prefix ends at a '.'
                            package_found = true;
                    }

                    // Every import-on-demand declaration must refer to a package declared in some file listed on the Joos command line.
                    if(!package_found)
                    {
                        std::cout << "Import-on-demand package" << package_name << " does not exist" << std::endl;
                        exit(42);
                    }
                }

                // Check that all single-type imports exist
                if(!import->declareAll)
                {
                    size_t last_delimiter = import->name->getString().find_last_of('.');
                    std::string single_type_name = import->name->getString().substr(last_delimiter + 1);
                    assert(last_delimiter != std::string::npos);
                    std::string import_package_name = import->name->getString().substr(0, last_delimiter);

                    bool import_exists = false;

                    for(const ASTNode* ast: asts)
                    {
                        const CompilerUnit* cunit = dynamic_cast<const CompilerUnit*>(ast);

                        // If package name matches and the type is in the package
                        if(cunit->packageDecl->name->getString() == import_package_name && 
                        cunit->typeDecl &&
                        cunit->typeDecl->getName()->getString() == single_type_name)
                        {
                            import_exists = true;
                        }
                    }

                    if(!import_exists)
                    {
                        std::cout << "Import " << import->name->getString() << " does not exist" <<  std::endl;
                        exit(42);
                    }
                }
                
                single_type_imports.insert(single_type_name);
            }
        }

        //No package names or prefixes of package names of declared packages, single-type-import declarations or 
        //import-on-demand declarations that are used may resolve to types, except for types in the default package.
        for(std::string package_name: used_package_names)
        {
            std::string prefix = package_name;
            size_t last_period = package_name.size();

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

// TODO Make all environment pointers point to closest scope?
Environment* getClosestScope(ASTNode* node)
{
    ASTNode* parent = node;
    while(parent && !parent->getEnvironment()) parent = parent->parent;
    assert(parent);
    return parent->getEnvironment();
}

// TODO Make all ASTNodes point to contained class?
ClassDeclaration* getEnclosingClass(ASTNode* node)
{
    ASTNode* parent = node;
    while(parent && !dynamic_cast<ClassDeclaration*>(parent)) parent = parent->parent;
    assert(parent);
    return dynamic_cast<ClassDeclaration*>(parent);
}

// Returns true if name is in the expression namespace, false otherwise.
bool resolveExpression(SimpleName* name)
{
    // If local var/ parameter exists in scope
    Environment* scanner = getClosestScope(name);
    while(scanner)
    {
        if(scanner->variables.find(name->id) != scanner->variables.end())
        {
            name->refers_to = scanner->variables[name->id];
            return true;
        }
        if(scanner->formal_params.find(name->id) != scanner->formal_params.end())
        {
            name->refers_to = scanner->formal_params[name->id];
            return true;
        }
        // a_2, ..., a_n are instance fields

        scanner = scanner->parent;
    }

    // If field is in contain set of current class
    ClassDeclaration* enclosing_class = getEnclosingClass(name);
    assert(enclosing_class->containedFields); // TODO Populate containedFields
    if(enclosing_class->containedFields->find(name->id) != enclosing_class->containedFields->end())
    {
        name->refers_to = (*enclosing_class->containedFields)[name->id];
        // a_2, ..., a_n are instance fields
        return true;
    }

    return false;
}

// Returns whether it succeeded in disambiguating exp
bool DisambiguationVisitor::disambiguate(const std::vector<Name*>& exp)
{
    // for(SimpleName* name: exp) std::cout << name->id << ".";
    // std::cout << std::endl;

    assert(exp.size());
    assert(!exp[0]->refers_to);
    assert(dynamic_cast<SimpleName*>(exp[0]));

    SimpleName* exp_base = dynamic_cast<SimpleName*>(exp[0]);
    std::string a1 = exp_base->id;

    // If local var/ parameter exists in scope
    // If field a1 is in contain set of current class (Done after in resolve Expression)
    resolveExpression(exp_base);

    // Shortest prefix that's a valid class
    if(!exp[0]->refers_to)
    {
        exp[0]->refers_to = linkSimpleName(exp_base, global, package_name, asts, ast_root, imports);
    }

    if(!exp[0]->refers_to)
    {
        for(Name* name: exp)
        {
            if(dynamic_cast<QualifiedName*>(name))
            {
                exp[0]->refers_to = linkQualifedName(dynamic_cast<QualifiedName*>(name), global, package_name, asts);
                if(exp[0]->refers_to) break;
            }
        }

        // ak+1 static field
        // ak+2, ..., an instance fields
    }

    // Failed to disambiguate exp
    if(!exp[0]->refers_to) return false;

    // Make each QualifiedName refer to what it's immediate SimpleName refers to.
    // For example, the QualifiedName for a.b.c would have c as the SimpleName, and so
    // a.b.c and c would point to the same thing.
    for(Name* name: exp)
    {
        // Second SimpleName overides first if more than one exist.
        if(name->refers_to && dynamic_cast<QualifiedName*>(name->parent))
        {
            dynamic_cast<QualifiedName*>(name->parent)->simpleName->refers_to = name->refers_to;
        } 
    }

    return true;
}

void DisambiguationVisitor::visit(NameExpression& node)
{
    // Create vector of each prefix of the QualifiedName
    std::vector<Name*> exp;

    Name* child = node.name;
    QualifiedName* qualified_child;
    while(qualified_child = dynamic_cast<QualifiedName*>(child))
    {
        exp.push_back(qualified_child);
        child = qualified_child->name;
    }
    exp.push_back(child);
    std::reverse(exp.begin(), exp.end());

    if(!disambiguate(exp))
    {
        std::cout << "Failed to disambiguate expression " << node.name->getString() << std::endl;
        exit(42);
    }
}

void DisambiguationVisitor::visit(CompilerUnit& node)
{
    assert(node.packageDecl);
    package_name = node.packageDecl->name->getString();
    imports = node.importDecls;
    ast_root = &node;
}

Type* cloneType(Type* type)
{
    if (PrimitiveType * primType = dynamic_cast<PrimitiveType*>(type))
    {
        PrimitiveType* clone = new PrimitiveType();
        clone->type = primType->type;
        return clone;
    }
    else if (QualifiedType * qualType = dynamic_cast<QualifiedType*>(type))
    {
        SimpleName* name = new SimpleName;

        if (SimpleName * simple = dynamic_cast<SimpleName*>(qualType->name))
        {
            name->id = simple->id;
        }
        else if (QualifiedName * qual = dynamic_cast<QualifiedName*>(qualType->name))
        {
            name->id = qual->simpleName->id;
        }
        name->refers_to = qualType->name->refers_to;

        assert(name->refers_to != nullptr);

        QualifiedType* clone = new QualifiedType();
        clone->name = name;
        return clone;
    }
    else if (ArrayType * arrayType = dynamic_cast<ArrayType*>(type))
    {
        ArrayType* clone = new ArrayType();
        clone->elementType = cloneType(arrayType->elementType);
        return clone;
    }

    return nullptr;
}

TypeCheckingVisitor::TypeCheckingVisitor(Environment* globalEnv)
    :globalEnvironment(globalEnv)
{
}

void TypeCheckingVisitor::visit(ClassDeclaration& node)
{
    enclosingClass = &node;
}

void TypeCheckingVisitor::visit(MethodDeclaration & node)
{
    returnType = node.type;
}

void TypeCheckingVisitor::visit(ConstructorDeclaration& node)
{
    PrimitiveType* voidType = new PrimitiveType();
    voidType->type = PrimitiveType::VOID;
    returnType = voidType;
}

void TypeCheckingVisitor::visit(Block& node)
{
    localEnvironment = node.getEnvironment();
}

void TypeCheckingVisitor::leave(ConstructorDeclaration& node)
{
    delete returnType;
    returnType = nullptr;
}

void TypeCheckingVisitor::leave(IntLiteral& node)
{
    PrimitiveType* type = new PrimitiveType();
    type->type = PrimitiveType::INT;
    node.resolvedType = type;
}

void TypeCheckingVisitor::leave(CharLiteral& node)
{
    PrimitiveType* type = new PrimitiveType();
    type->type = PrimitiveType::CHAR;
    node.resolvedType = type;
}

void TypeCheckingVisitor::leave(StringLiteral& node)
{
    // Create a type that refers to string
    SimpleName* stringName = new SimpleName;
    stringName->id = "String";
    stringName->refers_to = globalEnvironment->classes["java.lang.String"];

    assert(stringName->refers_to != nullptr);

    QualifiedType* stringType = new QualifiedType();
    stringType->name = stringName;

    node.resolvedType = stringType;
}

void TypeCheckingVisitor::leave(BooleanLiteral& node)
{
    PrimitiveType* type = new PrimitiveType();
    type->type = PrimitiveType::INT;
    node.resolvedType = type;
}

void TypeCheckingVisitor::leave(NullLiteral& node)
{
    PrimitiveType* type = new PrimitiveType();
    type->type = PrimitiveType::INT;
    node.resolvedType = type;
}

Environment resolveNames(std::vector<ASTNode*> asts)
{
    // Create environments
    EnvironmentVisitor env_visitor;
    for(ASTNode* ast: asts) ast->visitAll(env_visitor);
    Environment& global = env_visitor.global;

    // Resolve type names
    checkTypeLinking(&global, asts);
    TypeLinkingVisitor type_visitor(&global, asts);
    for(ASTNode* ast: asts) ast->visitAll(type_visitor);

    // Check class hierarchy
    CheckEnvironmentHierarchy(global);

    // Disambiguate ambiguous namespace and resolve expressions
    DisambiguationVisitor disambiguation_visitor(&global, asts);
    for(ASTNode* ast: asts) ast->visitAll(disambiguation_visitor);

    TypeCheckingVisitor type_check_visitor(&global);
    for (ASTNode* ast : asts) ast->visitAll(type_check_visitor);

    return global;
}