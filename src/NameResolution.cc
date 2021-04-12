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
        node.fullyQualifiedName = (package == UNNAMED_PACKAGE) ? "." + node.name->getString() : class_name;
        node.packageName = package;
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
        node.fullyQualifiedName = (package == UNNAMED_PACKAGE) ? "." + node.name->getString() : interface_name;
        node.packageName = package;
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
    // Class FieldDeclarations always use VariableDeclarationExpressions internally. 
    // Thus, fields will be recorded in both the class scope's fields AND variables.
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
                        if (package_name.size() <= other_package.size())
                        {
                            if (package_name == other_package.substr(0, package_name.size()))
                            {
                                if (package_name.size() == other_package.size() || other_package[package_name.size()] == '.')
                                {
                                    package_found = true;
                                }
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
bool resolveExpression(SimpleName* name, FieldDeclaration * currentField, bool & simpleNameUseBeforeDecl)
{
    if (currentField == nullptr){
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
    }

    // If field is in contain set of current class
    ClassDeclaration* enclosing_class = getEnclosingClass(name);
    assert(enclosing_class->containedFields); // TODO Populate containedFields
    if(enclosing_class->containedFields->find(name->id) != enclosing_class->containedFields->end())
    {
        name->refers_to = (*enclosing_class->containedFields)[name->id];
        // a_2, ..., a_n are instance fields

        if (currentField){ // inside a field initialization
            // check field usage is of a field that has already been declared
            auto *usage = dynamic_cast<FieldDeclaration *>(name->refers_to);
            assert(usage);
            // cout << enclosing_class->name->getString() << endl;
            // cout << "usage: " << name->id << enclosing_class->containedFieldsOrder[usage] << endl;
            // cout << "field: " << currentField->declaration->name->getString() << enclosing_class->containedFieldsOrder[currentField] << endl;

            if (enclosing_class->containedFieldsOrder[usage] 
                >= enclosing_class->containedFieldsOrder[currentField]){
                simpleNameUseBeforeDecl = true;
            }
        }

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
    resolveExpression(exp_base, currentField, simpleNameUseBeforeDecl);

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
                if (exp[0]->refers_to) 
                {
                    name->refers_to = exp[0]->refers_to;
                    break;
                }
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
void DisambiguationVisitor::leave(Expression& e){
    auto *assignExprParent = dynamic_cast<AssignmentExpression *>(e.parent);
    if (assignExprParent){
        if (assignExprParent->lhs == &e && simpleNameUseBeforeDecl){
            if (dynamic_cast<NameExpression*>(&e)){
                simpleNameUseBeforeDecl = false;
            }
        }
    }
}

void DisambiguationVisitor::visit(FieldDeclaration& f){
    currentField = &f;
    // cout << "enter field " << currentField->declaration->name->getString() << endl;
}

void DisambiguationVisitor::leave(FieldDeclaration& c){
    // cout << "exit field " << currentField->declaration->name->getString() << endl;
    currentField = nullptr;
    if (simpleNameUseBeforeDecl){
        cout << "invalid field usage before declaration" << endl;
        exit(42);
    }
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

Type* typeFromDecl(ClassDeclaration* decl)
{
    SimpleName* name = new SimpleName();
    name->id = decl->name->id;
    name->refers_to = decl;
    
    QualifiedType* type = new QualifiedType();
    type->name = name;
    
    return type;
}

bool TypeCheckingVisitor::isAssignable(Type* lhs, Type* rhs) const
{
    if (lhs && rhs)
    {
        if (PrimitiveType * primLhs = dynamic_cast<PrimitiveType*>(lhs))
        {
            if (PrimitiveType * primRhs = dynamic_cast<PrimitiveType*>(rhs))
            {
                if (primLhs->type == primRhs->type)
                {
                    return true;
                }

                switch (primLhs->type)
                {
                case PrimitiveType::INT:
                    if (primRhs->type == PrimitiveType::SHORT || primRhs->type == PrimitiveType::CHAR)
                    {
                        return true;
                    }
                case PrimitiveType::SHORT:
                    if (primRhs->type == PrimitiveType::BYTE)
                    {
                        return true;
                    }
                    break;
                }
            }
        }
        else if (isRefType(lhs) && isNullType(rhs))
        {
            return true;
        }
        else if (QualifiedType * qualLhs = dynamic_cast<QualifiedType*>(lhs))
        {
            if (QualifiedType * qualRhs = dynamic_cast<QualifiedType*>(rhs))
            {
                TypeDeclaration* lhsType = dynamic_cast<TypeDeclaration*>(qualLhs->name->refers_to);
                TypeDeclaration* rhsType = dynamic_cast<TypeDeclaration*>(qualRhs->name->refers_to);
                assert(lhsType != nullptr && rhsType != nullptr);
                return (lhsType->fullyQualifiedName == "java.lang.Object" && dynamic_cast<InterfaceDeclaration*>(rhsType)) ||
                    isDerived(lhsType, rhsType);
            }
            else if (ArrayType * arrayRhs = dynamic_cast<ArrayType*>(rhs))
            {
                if (TypeDeclaration * type = dynamic_cast<TypeDeclaration*>(qualLhs->name->refers_to))
                {
                    return type->fullyQualifiedName == "java.lang.Object" ||
                        type->fullyQualifiedName == "java.lang.Cloneable" ||
                        type->fullyQualifiedName == "java.io.Serializable";
                }
            }
        }
        else if (ArrayType * arrayLhs = dynamic_cast<ArrayType*>(lhs))
        {
            if (ArrayType * arrayRhs = dynamic_cast<ArrayType*>(rhs))
            {
                Type* lhsElemType = arrayLhs->elementType;
                Type* rhsElemType = arrayRhs->elementType;
                if (PrimitiveType * primLhs = dynamic_cast<PrimitiveType*>(lhsElemType))
                {
                    if (PrimitiveType * primRhs = dynamic_cast<PrimitiveType*>(rhsElemType))
                    {
                        return primLhs->type == primRhs->type;
                    }
                }
                else if (dynamic_cast<QualifiedType*>(lhsElemType) && dynamic_cast<QualifiedType*>(rhsElemType))
                {
                    return isAssignable(lhsElemType, rhsElemType);
                }
            }
        }

    }
    return false;
}

bool TypeCheckingVisitor::isDerived(TypeDeclaration* base, TypeDeclaration* derived) const
{
    if (base != nullptr)
    {
        if (base == derived)
        {
            return true;
        }
        if (ClassDeclaration * classDecl = dynamic_cast<ClassDeclaration*>(derived))
        {
            if (classDecl->baseClass == base) return true;
            for (InterfaceDeclaration* inter : *classDecl->interfaces)
            {
                if (inter == base) return true;
            }

            if (classDecl->baseClass && isDerived(base, classDecl->baseClass))
            {
                return true;
            }
            for (InterfaceDeclaration* inter : *classDecl->interfaces)
            {
                if (isDerived(base, inter)) return true;
            }
        }
        else if (InterfaceDeclaration * interDecl = dynamic_cast<InterfaceDeclaration*>(derived))
        {
            if (dynamic_cast<InterfaceDeclaration*>(base))
            {
                for (InterfaceDeclaration* inter : *interDecl->interfaces)
                {
                    if (inter == base) return true;
                }
                for (InterfaceDeclaration* inter : *interDecl->interfaces)
                {
                    if (isDerived(base, inter)) return true;
                }
            }
        }
    }

    return false;
}

bool TypeCheckingVisitor::isBooleanType(Type* type) const
{
    PrimitiveType* primType = dynamic_cast<PrimitiveType*>(type);
    return primType && primType->type == PrimitiveType::BOOLEAN;
}

bool TypeCheckingVisitor::isVoidType(Type* type) const
{
    PrimitiveType* primType = dynamic_cast<PrimitiveType*>(type);
    return primType && primType->type == PrimitiveType::VOID;
}

bool TypeCheckingVisitor::isStringType(Type* type) const
{
    QualifiedType* qualType = dynamic_cast<QualifiedType*>(type);
    if (qualType)
    {
        return qualType->name->refers_to == globalEnvironment->classes["java.lang.String"];
    }
    return false;
}

bool TypeCheckingVisitor::isRefType(Type* type) const
{
    return dynamic_cast<QualifiedType*>(type) || dynamic_cast<ArrayType*>(type);
}

bool TypeCheckingVisitor::isNullType(Type* type) const
{
    PrimitiveType* primType = dynamic_cast<PrimitiveType*>(type);
    return primType && primType->type == PrimitiveType::NULL_TYPE;
}

bool TypeCheckingVisitor::isInterfaceType(Type* type) const
{
    QualifiedType* qualType = dynamic_cast<QualifiedType*>(type);
    if (qualType)
    {
        return dynamic_cast<InterfaceDeclaration*>(qualType->name->refers_to);
    }

    return false;
}

bool TypeCheckingVisitor::isCastable(Type* baseType, Type* castType) const
{
    if (isNullType(castType))
    {
        return false;
    }

    if (isNumericType(baseType) && isNumericType(castType))
    {
        return true;
    }
    else if (PrimitiveType * primBase = dynamic_cast<PrimitiveType*>(baseType))
    {
        if (PrimitiveType * primCast = dynamic_cast<PrimitiveType*>(castType))
        {
            return primBase->type == primCast->type;
        }
        else
        {
            return primBase->type == PrimitiveType::NULL_TYPE;
        }
    }
    else if (QualifiedType * qualBase = dynamic_cast<QualifiedType*>(baseType))
    {
        if (QualifiedType * qualCast = dynamic_cast<QualifiedType*>(castType))
        {
            TypeDeclaration* baseDecl = dynamic_cast<TypeDeclaration*>(qualBase->name->refers_to);
            TypeDeclaration* castDecl = dynamic_cast<TypeDeclaration*>(qualCast->name->refers_to);
            assert(baseDecl != nullptr && castDecl != nullptr);

            if (isDerived(baseDecl, castDecl) || isDerived(castDecl, baseDecl))
            {
                return true;
            }

            InterfaceDeclaration* baseInter = dynamic_cast<InterfaceDeclaration*>(baseDecl);
            InterfaceDeclaration* castInter = dynamic_cast<InterfaceDeclaration*>(castDecl);

            if (baseInter && castInter)
            {
                return true;
            }
            
            if (baseInter)
            {
                ClassDeclaration* classDecl = dynamic_cast<ClassDeclaration*>(castDecl);
                for (Modifier* mod : classDecl->modifiers->elements)
                {
                    if (mod->type == Modifier::FINAL)
                    {
                        return false;
                    }
                }
                return true;
            }

            if (castInter)
            {
                ClassDeclaration* classDecl = dynamic_cast<ClassDeclaration*>(baseDecl);
                for (Modifier* mod : classDecl->modifiers->elements)
                {
                    if (mod->type == Modifier::FINAL)
                    {
                        return false;
                    }
                }
                return true;
            }
        }
        else if (dynamic_cast<ArrayType*>(castType))
        {
            TypeDeclaration* baseDecl = dynamic_cast<TypeDeclaration*>(qualBase->name->refers_to);

            return baseDecl->fullyQualifiedName == "java.lang.Object";
        }
    }
    else if (ArrayType * arrayBase = dynamic_cast<ArrayType*>(baseType))
    {
        if (ArrayType * arrayCast = dynamic_cast<ArrayType*>(castType))
        {
            Type* baseElemType = arrayBase->elementType;
            Type* castElemType = arrayCast->elementType;
            if (PrimitiveType * primBase = dynamic_cast<PrimitiveType*>(baseElemType))
            {
                if (PrimitiveType * primCast = dynamic_cast<PrimitiveType*>(castElemType))
                {
                    return primBase->type == primCast->type;
                }
            }
            else
            {
                return isCastable(arrayBase->elementType, arrayCast->elementType);
            }
        }
        else if (QualifiedType * qualType = dynamic_cast<QualifiedType*>(castType))
        {
            if (TypeDeclaration * type = dynamic_cast<TypeDeclaration*>(qualType->name->refers_to))
            {
                return type->fullyQualifiedName == "java.lang.Object" ||
                    type->fullyQualifiedName == "java.lang.Cloneable" ||
                    type->fullyQualifiedName == "java.io.Serializable";
            }
        }
    }

    return false;
}

bool TypeCheckingVisitor::validateMemberAccess(Expression* prevExpr, TypeDeclaration* accessingType, MemberDeclaration* member) const
{
    set<Modifier::ModifierType> mods;
    for (Modifier* mod : member->modifiers->elements)
    {
        mods.insert(mod->type);
    }

    bool shouldBeStatic = false;
    if (NameExpression * nameExpr = dynamic_cast<NameExpression*>(prevExpr))
    {
        if (nameExpr->refersToType)
        {
            shouldBeStatic = true;
        }
    }
    else if (prevExpr == nullptr)
    {
        if (isStaticContext)
        {
            cout << "Cannot use an implicit this in a static context" << endl;
            return false;
        }

        // Implicit this is always non static
        shouldBeStatic = false;
    }

    if (shouldBeStatic)
    {
        if(mods.find(Modifier::STATIC) == mods.end())
        {
            cout << "Accessing instance member when should be static member" << endl;
            return false;
        }
    }
    else
    {
        if(mods.find(Modifier::STATIC) != mods.end())
        {
            cout << "Accessing static member when should be instance member" << endl;
            return false;
        }
    }

    if (mods.find(Modifier::PROTECTED) != mods.end())
    {
        bool samePackage = member->originatingClass->packageName == enclosingClass->packageName;
        bool deriveClass = isDerived(member->originatingClass, enclosingClass);

        if (samePackage || deriveClass)
        {
            if (!samePackage && !shouldBeStatic)
            {
                if (!isDerived(enclosingClass, accessingType))
                {
                    cout << "For instance member the accessing type must be a subclass of enclosing type" << endl;
                    return false;
                }
            }
        }
        else
        {
            cout << "Cannot access protected member if not in a subtype or in same package" << endl;
            return false;
        }
    }

    return true;
}

bool TypeCheckingVisitor::validateConstructorAccess(ConstructorDeclaration* member) const
{
    set<Modifier::ModifierType> mods;
    for (Modifier* mod : member->modifiers->elements)
    {
        mods.insert(mod->type);
    }

    if (mods.find(Modifier::PROTECTED) != mods.end())
    {
        if (member->originatingClass->packageName != enclosingClass->packageName)
        {
            cout << "Cannot access protected Constructor if not in same package" << endl;
            return false;
        }
    }

    return true;
}

bool TypeCheckingVisitor::isNumericType(Type* type) const
{
    PrimitiveType* primType = dynamic_cast<PrimitiveType*>(type);
    if (primType)
    {
        switch (primType->type)
        {
        case PrimitiveType::BYTE:
        case PrimitiveType::CHAR:
        case PrimitiveType::INT:
        case PrimitiveType::SHORT:
            return true;
        }
    }
    return false;
}

TypeCheckingVisitor::TypeCheckingVisitor(Environment* globalEnv)
    :globalEnvironment(globalEnv), localEnvironment(nullptr), enclosingClass(nullptr), returnType(nullptr), isStaticContext(false)
{
}

void TypeCheckingVisitor::visit(ClassDeclaration& node)
{
    enclosingClass = &node;
}

void TypeCheckingVisitor::visit(MethodDeclaration & node)
{
    returnType = node.type;

    isStaticContext = false;
    for (Modifier* modifier : node.modifiers->elements)
    {
        if (modifier->type == Modifier::STATIC)
        {
            isStaticContext = true;
        }
    }
}

void TypeCheckingVisitor::visit(ConstructorDeclaration& node)
{
    PrimitiveType* voidType = new PrimitiveType();
    voidType->type = PrimitiveType::VOID;
    returnType = voidType;
    isStaticContext = false;

    if (node.id != enclosingClass->name->id)
    {
        cout << "Constructor name does not match class it was declared in" << endl;
        exit(42);
    }

    if (enclosingClass->fullyQualifiedName != "java.lang.Object")
    {
        bool superConstructorExists = false;
        for (MemberDeclaration* member : enclosingClass->baseClass->classBody->elements)
        {
            if (ConstructorDeclaration * constructor = dynamic_cast<ConstructorDeclaration*>(member))
            {
                if (constructor->parameters->elements.size() == 0)
                {
                    superConstructorExists = true;
                    break;
                }
            }
        }
        if (!superConstructorExists)
        {
            cout << "No 0 argument constructor in super class" << endl;
            exit(42);
        }
    }
}

void TypeCheckingVisitor::visit(Block& node)
{
    localEnvironment = node.getEnvironment();
}

void TypeCheckingVisitor::visit(NameExpression& node)
{
    if (node.name->refers_to == nullptr)
    {
        // hasn't been resolved in prev step so it must be an instance field
        QualifiedName* qualName = dynamic_cast<QualifiedName*>(node.name);
        node.field = new FieldAccess();
        node.field->name = qualName->simpleName;
        
        NameExpression* prevName = new NameExpression();
        prevName->name = qualName->name;
        node.field->prevExpr = prevName;
        node.field->parent = &node;
        
        qualName->simpleName = nullptr;
        qualName->name = nullptr;

        delete qualName;
        node.name = nullptr;
    }
}
void TypeCheckingVisitor::visit(FieldDeclaration& node)
{
    isStaticContext = false;
    for (Modifier* modifier : node.modifiers->elements)
    {
        if (modifier->type == Modifier::STATIC)
        {
            isStaticContext = true;
        }
    }
}

void TypeCheckingVisitor::leave(FieldDeclaration& node)
{
    isStaticContext = false;
}

void TypeCheckingVisitor::leave(MethodDeclaration& node)
{
    isStaticContext = false;
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
    type->type = PrimitiveType::BOOLEAN;
    node.resolvedType = type;
}

void TypeCheckingVisitor::leave(NullLiteral& node)
{
    PrimitiveType* type = new PrimitiveType();
    type->type = PrimitiveType::NULL_TYPE;
    node.resolvedType = type;
}

void TypeCheckingVisitor::leave(NameExpression& node)
{
    if (node.name)
    {
        if (node.name->refers_to == nullptr)
        {
            cout << "Name should be resolved by now" << endl;
            exit(42);
        }

        if (FormalParameter * param = dynamic_cast<FormalParameter*>(node.name->refers_to))
        {
            node.resolvedType = cloneType(param->type);
        }
        else if (FieldDeclaration * field = dynamic_cast<FieldDeclaration*>(node.name->refers_to))
        {
            bool isStatic = false;
            for (Modifier* modifier : field->modifiers->elements)
            {
                if (modifier->type == Modifier::STATIC)
                {
                    isStatic = true;
                }
            }

            if (!isStatic && isStaticContext)
            {
                cout << "Cannot use an implicit this in a static context (can only use static fields)" << endl;
                exit(42);
            }
            else
            {
                node.resolvedType = cloneType(field->declaration->type);
            }
        }
        else if (VariableDeclarationExpression * var = dynamic_cast<VariableDeclarationExpression*>(node.name->refers_to))
        {
            if (FieldDeclaration * field = dynamic_cast<FieldDeclaration*>(var->parent))
            {
                bool isStatic = false;
                for (Modifier* modifier : field->modifiers->elements)
                {
                    if (modifier->type == Modifier::STATIC)
                    {
                        isStatic = true;
                    }
                }

                if (!isStatic && isStaticContext)
                {
                    cout << "Cannot use an implicit this in a static context (can only use static fields)" << endl;
                    exit(42);
                }
            }

            node.resolvedType = cloneType(var->type);
        }
        else if (ClassDeclaration * type = dynamic_cast<ClassDeclaration*>(node.name->refers_to))
        {
            node.resolvedType = typeFromDecl(type);
            node.refersToType = true;
        }
        else
        {
            cout << "Should refer to one of the above" << endl;
            assert(false);
        }
    }
    else
    {
        if (node.field->resolvedType)
        {
            node.resolvedType = cloneType(node.field->resolvedType);
        }
        else
        {
            cout << "Field access of name expr did not resolve type" << endl;
            exit(42);
        }
    }
}

void TypeCheckingVisitor::leave(BinaryOperation& node)
{
    if (!node.lhs->resolvedType || !node.rhs->resolvedType)
    {
        cout << "Both sides of binary op must be type correct" << endl;
        exit(42);
    }

    switch (node.op)
    {
    case BinaryOperation::PLUS:
        // Special case because we can "add" strings
        if (isStringType(node.lhs->resolvedType) && !isVoidType(node.rhs->resolvedType))
        {
            node.resolvedType = cloneType(node.lhs->resolvedType);
            break;
        }
        else if (isStringType(node.rhs->resolvedType) && !isVoidType(node.lhs->resolvedType))
        {
            node.resolvedType = cloneType(node.rhs->resolvedType);
            break;
        }

    case BinaryOperation::MINUS:
    case BinaryOperation::TIMES:
    case BinaryOperation::DIVIDE:
    case BinaryOperation::REMAINDER:
        if (isNumericType(node.lhs->resolvedType) && isNumericType(node.rhs->resolvedType))
        {
            PrimitiveType* numType = new PrimitiveType();
            numType->type = PrimitiveType::INT;
            node.resolvedType = numType;
        }
        else
        {
            cout << "Binary math operator requires 2 numeric operands" << endl;
            exit(42);
        }
        break;
    case BinaryOperation::LT:
    case BinaryOperation::GT:
    case BinaryOperation::GEQ:
    case BinaryOperation::LEQ:
        if (isNumericType(node.lhs->resolvedType) && isNumericType(node.rhs->resolvedType))
        {
            PrimitiveType* boolType = new PrimitiveType();
            boolType->type = PrimitiveType::BOOLEAN;
            node.resolvedType = boolType;
        }
        else
        {
            cout << "Binary relational op requires 2 numeric operands" << endl;
            exit(42);
        }
        break;
    case BinaryOperation::AND:
    case BinaryOperation::OR:
    case BinaryOperation::XOR:
    case BinaryOperation::EAGER_AND:
    case BinaryOperation::EAGER_OR:
        if (isBooleanType(node.lhs->resolvedType) && isBooleanType(node.rhs->resolvedType))
        {
            PrimitiveType* boolType = new PrimitiveType();
            boolType->type = PrimitiveType::BOOLEAN;
            node.resolvedType = boolType;
        }
        else
        {
            cout << "Binary boolean op requires 2 boolean operands" << endl;
            exit(42);
        }
        break;
    case BinaryOperation::EQ:
    case BinaryOperation::NEQ:

        bool isBoolComp = isBooleanType(node.lhs->resolvedType) && isBooleanType(node.rhs->resolvedType);
        bool isNumComp = isNumericType(node.lhs->resolvedType) && isNumericType(node.rhs->resolvedType);

        bool lhsRefOrNull = isRefType(node.lhs->resolvedType) || isNullType(node.lhs->resolvedType);
        bool rhsRefOrNull = isRefType(node.rhs->resolvedType) || isNullType(node.rhs->resolvedType);
        bool isObjectComp = lhsRefOrNull && rhsRefOrNull && (isCastable(node.lhs->resolvedType, node.rhs->resolvedType) || isCastable(node.rhs->resolvedType, node.lhs->resolvedType));

        if (isBoolComp || isNumComp || isObjectComp)
        {
            PrimitiveType* boolType = new PrimitiveType();
            boolType->type = PrimitiveType::BOOLEAN;
            node.resolvedType = boolType;
        }
        else
        {
            cout << "Equality op requires both boolean, numeric, or ref/null operands of castable type" << endl;
            exit(42);
        }
    }
}

void TypeCheckingVisitor::leave(PrefixOperation& node)
{
    if (node.operand->resolvedType == nullptr)
    {
        cout << "Operand of prefix expression was not type checked" << endl;
        exit(42);
    }

    switch (node.op)
    {
    case PrefixOperation::NOT:
        if (isBooleanType(node.operand->resolvedType))
        {
            node.resolvedType = cloneType(node.operand->resolvedType);
        }
        else
        {
            cout << "Operand of not expression is not a boolean expression" << endl;
            exit(42);
        }
        break;
    case PrefixOperation::MINUS:
        if (isNumericType(node.operand->resolvedType))
        {
            node.resolvedType = cloneType(node.operand->resolvedType);
        }
        else
        {
            cout << "Operand of minus expression is not a numeric expression" << endl;
            exit(42);
        }
    }
}

void TypeCheckingVisitor::leave(CastExpression& node)
{
    if (isCastable(node.expression->resolvedType, node.castType))
    {
        node.resolvedType = cloneType(node.castType);
    }
    else
    {
        cout << "Type is not castable in cast expression" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(AssignmentExpression& node)
{
    if (node.lhs->resolvedType == nullptr)
    {
        cout << "LHS of assignment was not type checked" << endl;
        exit(42);
    }

    if (node.rhs->resolvedType == nullptr)
    {
        cout << "RHS of assignment was not type checked" << endl;
        exit(42);
    }

    if (isAssignable(node.lhs->resolvedType, node.rhs->resolvedType))
    {
        if (NameExpression * nameLhs = dynamic_cast<NameExpression*>(node.lhs))
        {
            if (nameLhs->name)
            {
                if (FieldDeclaration * field = dynamic_cast<FieldDeclaration*>(nameLhs->name->refers_to))
                {
                    for (Modifier* mod : field->modifiers->elements)
                    {
                        if (mod->type == Modifier::FINAL)
                        {
                            cout << "Cannot assign to a final field" << endl;
                            exit(42);
                        }
                    }
                }
                else if (VariableDeclarationExpression * var = dynamic_cast<VariableDeclarationExpression*>(nameLhs->name->refers_to))
                {
                    if (FieldDeclaration * field = dynamic_cast<FieldDeclaration*>(var->parent))
                    {
                        for (Modifier* mod : field->modifiers->elements)
                        {
                            if (mod->type == Modifier::FINAL)
                            {
                                cout << "Cannot assign to a final field" << endl;
                                exit(42);
                            }
                        }
                    }

                    node.resolvedType = cloneType(var->type);
                }
            }
            else
            {
                if (nameLhs->field->refersTo)
                {
                    for (Modifier* mod : nameLhs->field->refersTo->modifiers->elements)
                    {
                        if (mod->type == Modifier::FINAL)
                        {
                            cout << "Cannot assign to a final field" << endl;
                            exit(42);
                        }
                    }
                }
                else
                {
                    cout << "Cannot assign to length field of array" << endl;
                    exit(42);
                }
            }
        }
        else if (FieldAccess * fieldLhs = dynamic_cast<FieldAccess*>(node.lhs))
        {
            if (fieldLhs->refersTo)
            {
                for (Modifier* mod : fieldLhs->refersTo->modifiers->elements)
                {
                    if (mod->type == Modifier::FINAL)
                    {
                        cout << "Cannot assign to a final field" << endl;
                        exit(42);
                    }
                }
            }
            else
            {
                cout << "Cannot assign to length field of array" << endl;
                exit(42);
            }
        }

        node.resolvedType = cloneType(node.lhs->resolvedType);
    }
    else
    {
        cout << "RHS was not assignable to LHS of assignment epxresion" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(ParenthesizedExpression& node)
{
    if (NameExpression * name = dynamic_cast<NameExpression*>(node.expr))
    {
        if (name->refersToType)
        {
            cout << "Cannot have a type name in a parenthesized expression" << endl;
            exit(42);
        }
    }

    node.resolvedType = cloneType(node.expr->resolvedType);
}

void TypeCheckingVisitor::leave(ClassInstanceCreator& node)
{
    for (Expression* expression : node.arguments->elements)
    {
        if (expression->resolvedType == nullptr)
        {
            cout << "An argument type has not been resolved in a constructor call" << endl;
            exit(42);
        }
    }

    if (ClassDeclaration * classDecl = dynamic_cast<ClassDeclaration*>(node.type->name->refers_to))
    {
        for (Modifier* modifier: classDecl->modifiers->elements)
        {
            if (modifier->type == Modifier::ABSTRACT)
            {
                cout << "Cannot create an instance of an abstract class" << endl;
                exit(42);
            }
        }

        for (MemberDeclaration* member : classDecl->classBody->elements)
        {
            if (ConstructorDeclaration * constructor = dynamic_cast<ConstructorDeclaration*>(member))
            {
                // check arguments
                if (constructor->parameters->elements.size() == node.arguments->elements.size())
                {
                    bool match = true;
                    for (size_t i = 0; i < constructor->parameters->elements.size(); i++)
                    {
                        if (constructor->parameters->elements[i]->type->getTypeName() != node.arguments->elements[i]->resolvedType->getTypeName())
                        {
                            match = false;
                            break;
                        }
                    }
                    
                    if (match)
                    {
                        if (validateConstructorAccess(constructor))
                        {
                            node.resolvedType = cloneType(node.type);
                            node.matchedConstructor = constructor;
                            return;
                        }
                        else
                        {
                            exit(42);
                        }
                    }
                }
            }
        }

        cout << "Couldn't find a matching constructor" << endl;
        exit(42);
    }
    else
    {
        cout << "Trying to construct non-class type" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(ArrayCreator& node)
{
    if (isNumericType(node.argument->resolvedType))
    {
        node.resolvedType = cloneType(node.type);
    }
    else
    {
        cout << "Array creator requires a numeric type argument" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(MethodCall& node)
{
    string methodSig = "method_" + node.name->getString() + "_args";

    for (Expression* expression : node.arguments->elements)
    {
        if (expression->resolvedType == nullptr)
        {
            cout << "An argument type has not been resolved in a constructor call" << endl;
            exit(42);
        }
        methodSig += "_" + expression->resolvedType->getTypeName();
    }

    TypeDeclaration* callingType;
    if (node.prevExpr)
    {
        if (node.prevExpr->resolvedType)
        {
            if (QualifiedType * typeDecl = dynamic_cast<QualifiedType*>(node.prevExpr->resolvedType))
            {
                callingType = dynamic_cast<TypeDeclaration*>(typeDecl->name->refers_to);
            }
            else
            {
                cout << "Prev expression to method call is not class/interface type" << endl;
                exit(42);
            }
        }
        else
        {
            cout << "Prev expression to method call has not been type checked" << endl;
            exit(42);
        }
    }
    else
    {
        callingType = enclosingClass;
    }
    
    MethodDeclaration* method = nullptr;
    if (callingType->containedAbstractMethods->find(methodSig) != callingType->containedAbstractMethods->end())
    {
        method = callingType->containedAbstractMethods->at(methodSig)[0];
    }

    if (!method)
    {
        if (ClassDeclaration * classDecl = dynamic_cast<ClassDeclaration*>(callingType))
        {
            if (classDecl->containedConcreteMethods->find(methodSig) != classDecl->containedConcreteMethods->end())
            {
                method = classDecl->containedConcreteMethods->at(methodSig);
            }
        }
    }

    if (method)
    {
        if (validateMemberAccess(node.prevExpr, callingType, method))
        {
            node.resolvedType = cloneType(method->type);
        }
        else
        {
            exit(42);
        }
    }
    else
    {
        cout << "Couldn't find a matching method declaration" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(FieldAccess& node)
{
    QualifiedType* qualType = dynamic_cast<QualifiedType*>(node.prevExpr->resolvedType);
    if (qualType)
    {
        if (ClassDeclaration * classDecl = dynamic_cast<ClassDeclaration*>(qualType->name->refers_to))
        {
            if (classDecl->containedFields->find(node.name->id) != classDecl->containedFields->end())
            {
                FieldDeclaration* field = classDecl->containedFields->at(node.name->id);

                if (validateMemberAccess(node.prevExpr, classDecl, field))
                {
                    node.resolvedType = cloneType(field->declaration->type);
                    node.refersTo = field;
                }
                else
                {
                    exit(42);
                }
            }
            else
            {
                cout << "Trying to access a field " + node.name->id + " that does not exist in Class " + classDecl->fullyQualifiedName << endl;
                exit(42);
            }
        }
    }
    else if (dynamic_cast<ArrayType*>(node.prevExpr->resolvedType))
    {
        if (node.name->id == "length")
        {
            PrimitiveType* primType = new PrimitiveType();
            primType->type = PrimitiveType::INT;
            node.resolvedType = primType;
        }
        else
        {
            cout << "Trying to call field of array type that isn't .length" << endl;
            exit(42);
        }
    }
    else
    {
        cout << "Prev expression of field access does not resolve to a Class" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(ArrayAccess& node)
{
    if (ArrayType * arrayType = dynamic_cast<ArrayType*>(node.prevExpr->resolvedType))
    {
        if (isNumericType(node.indexExpr->resolvedType))
        {
            node.resolvedType = cloneType(arrayType->elementType);
        }
        else
        {
            cout << "Array access expression is not a numeric type" << endl;
            exit(42);
        }
    }
    else
    {
        cout << "Trying to access element of non-array type" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(ThisExpression& node)
{
    if (!isStaticContext)
    {
        node.resolvedType = typeFromDecl(enclosingClass);
    }
    else
    {
        cout << "Cannot use a this expression in a static context" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(VariableDeclarationExpression& node)
{
    if (node.initializer)
    {
        if (node.initializer->resolvedType == nullptr)
        {
            cout << "Initializer of variable declaration was not type checked" << endl;
            exit(42);
        }

        if (isAssignable(node.type, node.initializer->resolvedType))
        {
            node.resolvedType = cloneType(node.type);
        }
        else
        {
            cout << "Initializer was not assignable to variable declaration" << endl;
            exit(42);
        }
    }
    else
    {
        node.resolvedType = cloneType(node.type);
    }
}

void TypeCheckingVisitor::leave(InstanceOfExpression& node)
{
    if ((isRefType(node.expression->resolvedType) || isNullType(node.expression->resolvedType)) && isRefType(node.type))
    {
        if (isCastable(node.expression->resolvedType, node.type))
        {
            PrimitiveType* primType = new PrimitiveType();
            primType->type = PrimitiveType::BOOLEAN;
            node.resolvedType = primType;
        }
        else
        {
            cout << "Type is not castable in instanceof expression" << endl;
            exit(42);
        }
    }
    else
    {
        cout << "Instanceof must be between reference types" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(ExpressionStatement& node)
{
    if (node.expression->resolvedType)
    {
        node.isTypeCorrect = true;
    }
    else
    {
        cout << "Expression of expression statement does not have resolved type" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(EmptyStatement& node)
{
    node.isTypeCorrect = true;
}

void TypeCheckingVisitor::leave(ReturnStatement& node)
{
    if (node.expression)
    {
        if (!isVoidType(returnType))
        {
            if (node.expression->resolvedType)
            {
                if (isAssignable(returnType, node.expression->resolvedType))
                {
                    node.isTypeCorrect = true;
                }
                else
                {
                    cout << "Return expression is not assignable to return type" << endl;
                    exit(42);
                }
            }
            else
            {
                cout << "Expression has not been resolved" << endl;
                exit(42);
            }
        }
        else
        {
            cout << "Cannot return expression in a void func" << endl;
            exit(42);
        }
    }
    else
    {
        if (isVoidType(returnType))
        {
            node.isTypeCorrect = true;
        }
        else
        {
            cout << "Can only use a return without an expression in a void func" << endl;
            exit(42);
        }
    }
}

void TypeCheckingVisitor::leave(IfStatement& node)
{
    if (isBooleanType(node.ifCondition->resolvedType))
    {
        if (node.ifBody->isTypeCorrect)
        {
            if (node.elseBody)
            {
                if (node.elseBody->isTypeCorrect)
                {
                    node.isTypeCorrect = true;
                }
                else
                {
                    cout << "Else body is not type correct" << endl;
                }
            }
            else
            {
                node.isTypeCorrect = true;
            }
        }
        else
        {
            cout << "If body is not type correct" << endl;
            exit(42);
        }
    }
    else
    {
        cout << "If condition is not resolved to boolean" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(ForStatement& node)
{
    if (node.forInit && node.forInit->resolvedType == nullptr)
    {
        cout << "ForInit does not resolve to a type" << endl;
        exit(42);
    }

    if (node.forCheck && !isBooleanType(node.forCheck->resolvedType))
    {
        cout << "ForCheck does not resolve to a boolean type" << endl;
        exit(42);
    }

    if (node.forUpdate && node.forUpdate->resolvedType == nullptr)
    {
        cout << "ForUpdate does not resolve to a type" << endl;
        exit(42);
    }

    if (node.body->isTypeCorrect)
    {
        node.isTypeCorrect = true;
    }
    else
    {
        cout << "For body is not type correct" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(WhileStatement& node)
{
    if (isBooleanType(node.condition->resolvedType))
    {
        if (node.body->isTypeCorrect)
        {
            node.isTypeCorrect = true;
        }
        else
        {
            cout << "While body is not type correct" << endl;
            exit(42);
        }
    }
    else
    {
        cout << "While condition is not resolved to boolean" << endl;
        exit(42);
    }
}

void TypeCheckingVisitor::leave(Block& node)
{
    for (Statement* statement : node.statements->elements)
    {
        if (!statement->isTypeCorrect)
        {
            cout << "Statement within block is not type correct" << endl;
            exit(42);
        }
    }
    node.isTypeCorrect = true;
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