#pragma once

#include <vector>
#include <memory>
#include <exception>

enum class RegexNodeType
{
    START,
    PAREN,
    STAR,
    PLUS,
    QUESTION,
    OR,
    WILDCARD,
    BRACKET,
    BRACKET_NOT,
    CHAR
};

std::string regexNodeTypeToString(RegexNodeType type);

struct RegexNode
{
    RegexNodeType type;

    std::vector<std::unique_ptr<RegexNode>> children;

    char character;
    std::vector<std::pair<char, char>> bracket_chars;

    void print(size_t tabs = 0);
};

class InvalidRegexException: public std::exception
{
    std::string msg;
public:
    InvalidRegexException(const std::string& msg): msg(msg) {}

    virtual const char* what() const throw () {
       return msg.c_str();
    }
};

class RegexProcessor
{
    // Adds a new node to parent's children, and moves the previous last
    // child into this new node's children.
    void swapLastChild(RegexNode* parent, RegexNodeType type);

public:
    RegexNode process(const std::string& input);
};