#include "RegexProcessor.h"
#include <iostream>
#include <stack>

std::string regexNodeTypeToString(RegexNodeType type)
{
    switch(type)
    {
        case RegexNodeType::START:       return "START";
        case RegexNodeType::PAREN:       return "PAREN";
        case RegexNodeType::STAR:        return "STAR";
        case RegexNodeType::PLUS:        return "PLUS";
        case RegexNodeType::QUESTION:    return "QUESTION";
        case RegexNodeType::OR:          return "OR";
        case RegexNodeType::WILDCARD:    return "WILDCARD";
        case RegexNodeType::CHAR:        return "CHAR";
        case RegexNodeType::BRACKET:     return "BRACKET";
        case RegexNodeType::BRACKET_NOT: return "BRACKET_NOT";
        default: return "UNKNOWN_TYPE";
    }
}

void RegexNode::print(size_t tabs)
{
    for(size_t i = 0; i < tabs; i++) std::cout << "  ";

    std::cout << regexNodeTypeToString(type);

    if(type == RegexNodeType::CHAR) std::cout << " " << character;
    else if (type == RegexNodeType::BRACKET || type == RegexNodeType::BRACKET_NOT) 
    {
        for(auto& p: bracket_chars)
        {
            if(p.first == p.second) std::cout << " " << p.first; 
            else std::cout  << " " << p.first << "-" << p.second; 
        }
    }

    std::cout << std::endl; 

    for(auto& node: children) node.get()->print(tabs + 1);
}

void RegexProcessor::swapLastChild(RegexNode* parent, RegexNodeType type)
{
    auto new_node = std::make_unique<RegexNode>();
    new_node->type = type;
    new_node->children.push_back(std::move(parent->children.back()));

    parent->children.pop_back();
    parent->children.push_back(std::move(new_node));
}

// Modifies "represents" and returns true if the escape sequence "escape" 
// represents a special character. Otherwise, does not modify "represents"
// and returns false.
bool specialEscape(char escape, char& represents)
{
    switch(escape)
    {
        case 'n': represents = '\n'; break;
        case 'r': represents = '\r'; break;
        case 't': represents = '\t'; break;
        case 'v': represents = '\v'; break;
        case 'f': represents = '\f'; break;
        case '0': represents = '\0'; break;
        case '\\': represents = '\\'; break;
        default: 
            return false;
    }
    return true;
}

RegexNode RegexProcessor::process(const std::string& input)
{
    std::stack<RegexNode*> visited;

    size_t index = 0;
    RegexNode result;
    result.type = RegexNodeType::START;
    visited.push(&result);

    auto updateOr = [&visited]()
    {
        if(visited.top()->type == RegexNodeType::OR && visited.top()->children.size() == 2)
        {
            visited.pop();
        }
    };

    while(index < input.size())
    {     
        switch(input[index])
        {
            case '(':
                updateOr();
                visited.top()->children.push_back(std::make_unique<RegexNode>());
                visited.top()->children.back()->type = RegexNodeType::PAREN;
                visited.push(visited.top()->children.back().get());
                break;

            case ')':
                updateOr();
                if(visited.top()->type != RegexNodeType::PAREN)
                {
                    std::cout << visited.top()->children.size() << std::endl;
                    if(visited.top()->type == RegexNodeType::OR) std::cout << "OR FOUND" << std::endl;
                    throw InvalidRegexException(std::string("Mismatched parenthesis at ") 
                                                + std::to_string(index) + " in " + input);
                } 
                visited.pop();
                break;

            case '[':
                updateOr();
                visited.top()->children.push_back(std::make_unique<RegexNode>());
                if(input[index + 1] == '^')
                {
                    visited.top()->children.back()->type = RegexNodeType::BRACKET_NOT;
                    index++;
                }
                else
                {
                    visited.top()->children.back()->type = RegexNodeType::BRACKET;
                }
                
                index++;
                
                while(input[index] != ']')
                {
                    if(input[index] == '-')
                    {
                        index++;
                        visited.top()->children.back()->bracket_chars.back().second = input[index];
                    }
                    else
                    {
                        char c = input[index];
                        
                        if(input[index] == '\\')
                        {
                            index++;

                            if(!specialEscape(input[index], c))
                            {
                                throw InvalidRegexException(std::string("Invalid character escape at ") 
                                                            + std::to_string(index) + " in " + input);
                            }
                        }

                        visited.top()->children.back()->bracket_chars.push_back({c, c});
                    }
                        

                    index++;
                }
                break;

            case '*':
                swapLastChild(visited.top(), RegexNodeType::STAR);
                break;

            case '+':
                swapLastChild(visited.top(), RegexNodeType::PLUS);
                break;

            case '?':
                swapLastChild(visited.top(), RegexNodeType::QUESTION);
                break;

            case '|':
                swapLastChild(visited.top(), RegexNodeType::OR);
                visited.push(visited.top()->children.back().get());
                break;

            case '.':
                visited.top()->children.push_back(std::make_unique<RegexNode>());
                visited.top()->children.back()->type = RegexNodeType::WILDCARD;
                break;

            case '\\':
                index++;
                // Similar to default case which handles CHAR
                {
                    char c = input[index];
                    specialEscape(input[index], c);
                    
                    updateOr();
                    visited.top()->children.push_back(std::make_unique<RegexNode>());
                    visited.top()->children.back()->type = RegexNodeType::CHAR;
                    visited.top()->children.back()->character = c;
                }
                break;
            
            default:
                updateOr();
                visited.top()->children.push_back(std::make_unique<RegexNode>());
                visited.top()->children.back()->type = RegexNodeType::CHAR;
                visited.top()->children.back()->character = input[index];
                break;
        }

        index++;
    }

    return result;
}