#include "FA.h"
#include <iostream>
#include <assert.h>
#include <set>
#include <map>
#include <limits>
#include <queue>
#include <algorithm>

NFA orNFA(NFA& a, NFA& b)
{
    NFA result;
    size_t second_start = a.size() + 1;
    rebaseNFA(b, second_start);
    rebaseNFA(a, 1);
    result.emplace_back(false);
    result.insert( result.end(), a.begin(), a.end() );
    result.insert( result.end(), b.begin(), b.end() );
    result[0].transitions.emplace_back(TransitionType::EPSILON, 0, 1);
    result[0].transitions.emplace_back(TransitionType::EPSILON, 0, second_start);
    return result;
}

NFA RegexNodeToNFA(const RegexNode* rnode)
{
    std::vector<NFA> children_nfa;

    // Create NFAs for children
    for(auto& child: rnode->children) 
        children_nfa.push_back(RegexNodeToNFA(child.get()));

    NFA result;

    // Combine children NFAs based on current nodes type
    switch(rnode->type)
    {
        case RegexNodeType::START:
        case RegexNodeType::PAREN:
            {
                assert(children_nfa.size() > 0);

                // For each NFA but the last, append it to the result, and make all its accepting states
                // have an epsilon transition to the state right after the NFA.
                size_t base = 0;
                for(size_t i = 0; i < children_nfa.size() - 1; i++)
                {
                    NFA& nfa = children_nfa[i];

                    rebaseNFA(nfa, base);

                    base += nfa.size();

                    for(NFANode& node: nfa)
                    {
                        if(node.accept)
                        {
                            node.accept = false;
                            node.transitions.emplace_back(TransitionType::EPSILON, 0, base);
                        }
                    }

                    result.insert( result.end(), nfa.begin(), nfa.end() );
                }
                rebaseNFA(children_nfa.back(), result.size());
                result.insert( result.end(), children_nfa.back().begin(), children_nfa.back().end() );
            }
            break;

        case RegexNodeType::STAR:
            assert(children_nfa.size() == 1);
            assert(children_nfa[0].size() > 0);
            // All accept states get an epsilon transition to the start state,
            // and start state becomes an accept state
            for(NFANode& node: children_nfa[0])
            {
                if(node.accept)
                {
                    node.transitions.emplace_back(TransitionType::EPSILON, 0, 0);
                }
            }
            children_nfa[0][0].accept = true;
            result = children_nfa[0];
            break;

        case RegexNodeType::PLUS:
            assert(children_nfa.size() == 1);
            assert(children_nfa[0].size() > 0);
            // All accept states get an epsilon transition to the start state
            for(NFANode& node: children_nfa[0])
            {
                if(node.accept)
                {
                    node.transitions.emplace_back(TransitionType::EPSILON, 0, 0);
                }
            }
            result = children_nfa[0];
            break;

        case RegexNodeType::QUESTION:
            assert(children_nfa.size() == 1);
            assert(children_nfa[0].size() > 0);
            // Make start state an accept state
            children_nfa[0][0].accept = true;
            result = children_nfa[0];
            break;

        case RegexNodeType::OR:
            assert(children_nfa.size() == 2); // TODO Make verify function for RegexNode
            {
                result = orNFA(children_nfa[0], children_nfa[1]);
            }
            break;

        case RegexNodeType::WILDCARD:
            result.emplace_back(false);
            result.emplace_back(true);
            result[0].transitions.emplace_back(TransitionType::ANY, 0, 1);
            break;

        case RegexNodeType::BRACKET:
            result.emplace_back(false);
            result.emplace_back(true);
            for(std::pair<char, char> char_range: rnode->bracket_chars)
            {
                assert(char_range.first <= char_range.second);
                if(char_range.first == char_range.second)
                {
                    result[0].transitions.emplace_back(TransitionType::CHAR, char_range.first, 1);
                }
                else
                {
                    for(char c = char_range.first; c != char_range.second; c++)
                    {
                        result[0].transitions.emplace_back(TransitionType::CHAR, c, 1);
                    }
                }
            }
            break;

        case RegexNodeType::BRACKET_NOT:
            result.emplace_back(false);
            result.emplace_back(true);
            for(std::pair<char, char> char_range: rnode->bracket_chars)
            {
                assert(char_range.first <= char_range.second);
                if(char_range.first == char_range.second)
                {
                    result[0].transitions.emplace_back(TransitionType::NOT_CHAR, char_range.first, 1);
                }
                else
                {
                    for(char c = char_range.first; c != char_range.second; c++)
                    {
                        result[0].transitions.emplace_back(TransitionType::NOT_CHAR, c, 1);
                    }
                }
            }
            break;

        case RegexNodeType::CHAR:
            result.emplace_back(false);
            result.emplace_back(true);
            result[0].transitions.emplace_back(TransitionType::CHAR, rnode->character, 1);
            break;   

        default:
            throw std::runtime_error("Invalid RegexNode type encountered during NFA creation");
    }

    std::cout << regexNodeTypeToString(rnode->type) << " " << result.size() << std::endl;

    return result;
}

void rebaseNFA(NFA& nfa, size_t new_base)
{
    for(NFANode& node: nfa)
    {
        for(auto& trans: node.transitions)
        {
            std::get<2>(trans) += new_base;
        }
    }
}

// Returns rule with highest priority
int minRule(const NFA& nfa, const std::set<size_t>& states)
{
    size_t result = NO_RULE;
    for(size_t state: states)
    {
        result = std::min(result, nfa[state].rule);
    }
    return result;
}


void epsilonClosure(const NFA& nfa, size_t state, std::set<size_t>& result)
{
    result.insert(state);

    for(auto& trans: nfa[state].transitions)
    {
        size_t new_state = std::get<2>(trans);
        assert(new_state < nfa.size());

        // Do not follow epsilon transition cycles, these states are already in our result.
        if(std::get<0>(trans) == TransitionType::EPSILON 
           && result.find(new_state) == result.end()) 
        {
            epsilonClosure(nfa, new_state, result);
        }
    }
}

bool isAccept(const NFA& nfa, const std::set<size_t>& state)
{
    for(size_t node: state)
    {
        if(nfa[node].accept) return true;
    }

    return false;
}

NFA NFAToDFA(NFA nfa)
{
    std::map<std::set<size_t>, size_t> dfa_states;
    std::map<size_t, std::set<size_t>> closures;
    std::queue<std::set<size_t>> new_states; // TODO Rename
    NFA dfa;

    // Calculate the epsilon closure for every state
    for(size_t node_index = 0; node_index != nfa.size(); node_index++)
    {
        std::set<size_t> closure;
        epsilonClosure(nfa, node_index, closure);

        if(dfa_states.find(closure) == dfa_states.end())
        {
            dfa_states.insert({closure, dfa.size()});
            dfa.emplace_back(isAccept(nfa, closure));
            dfa.back().rule = minRule(nfa, closure);
            new_states.push(closure);
            closures[node_index] = closure;
        }
    }

    // Make all CHAR transitions that could possibly lead to an ANY transiton also lead to
    // the destination of the ANY transition via the same character. Also add an ANY transition 
    // going to the original ANY destination (which has lower precedence).
    // Similar to following NOT_CHAR adjustments.
    for(size_t node_index = 0; node_index != nfa.size(); node_index++)
    {
        NFANode& nfa_node = nfa[node_index];
        size_t original_transition_count = nfa_node.transitions.size();

        // Create set containing all states that have node_index as part of their epsilon closures
        std::set<size_t> surrounding_closures;
        for(auto const& [state, closure] : closures)
        {
            if(closure.find(node_index) != closure.end())
            {
                // std::cout << "ALALALLALALALALLA" << surrounding_closures.size() << std::endl;
                surrounding_closures.insert(closure.begin(), closure.end());
            }
        }
        
        // Get all ANY transtions characters for each destination from this node
        std::set<size_t> any_transitions;
        for(Transition& trans: nfa_node.transitions)
        {
            if(std::get<0>(trans) == TransitionType::ANY)
            {
                any_transitions.insert(std::get<2>(trans));
            }
        }

        // For all nodes in all the closures that the node is a part of,
        // add a transition going to the ANY destination
        std::vector<Transition> new_transitions;
        for(size_t dest : any_transitions)
        {
            for(size_t i: surrounding_closures)
            {
                NFANode& node = nfa[i];

                for(Transition& trans: node.transitions)
                {
                    // If a transition is a char transition that's not blocked by not_char then
                    // add another transition on this character to dest.
                    if(std::get<0>(trans) == TransitionType::CHAR)
                    {
                        // std::cout << "HERE ---------------- adding " << i << " -"  << std::get<1>(trans) << "-> " << dest << std::endl;
                        new_transitions.emplace_back(TransitionType::CHAR, std::get<1>(trans), dest);
                    }
                }
                new_transitions.emplace_back(TransitionType::ANY, '@', dest);
            }
        }
        nfa_node.transitions.insert( nfa_node.transitions.end(), new_transitions.begin(), new_transitions.end() );
    }

    // Convert all NOT_CHAR int CHAR and ANY.
    // Make all CHAR transitions that could possibly lead to a NOT_CHAR transiton with a different character
    // also lead to the destination of the NOT_CHAR transition.
    for(size_t node_index = 0; node_index != nfa.size(); node_index++)
    {
        NFANode& nfa_node = nfa[node_index];
        size_t original_transition_count = nfa_node.transitions.size();

        // Create a set containing all states that have node_index as part of their epsilon closures
        std::set<size_t> surrounding_closures;
        for(auto const& [state, closure] : closures)
        {
            if(closure.find(node_index) != closure.end())
            {
                surrounding_closures.insert(closure.begin(), closure.end());
            }
        }

        // Get all NOT_CHAR transtion characters corresponding to each destination from this node
        std::map<size_t, std::set<char>> not_transitions;
        for(Transition& trans: nfa_node.transitions)
        {
            if(std::get<0>(trans) == TransitionType::NOT_CHAR)
            {
                not_transitions[std::get<2>(trans)].insert(std::get<1>(trans));
            }
        }

        // For all nodes in all the closures that the node is a part of,
        // add a transition going to the NOT_CHAR destination if they have a transtion going anywhere
        // via a character that doesn't match the NOT_CHAR. Also add an ANY transition going to the 
        // NOT_CHAR destination (which has lower precedence).
        std::vector<Transition> new_transitions;
        for(auto const& [dest, not_chars] : not_transitions)
        {
            for(size_t i: surrounding_closures)
            {
                NFANode& node = nfa[i];

                for(Transition& trans: node.transitions)
                {
                    // If a transition is a CHAR transition that's not blocked by NOT_CHAR then
                    // add another transition on this character to dest.
                    if(std::get<0>(trans) == TransitionType::CHAR 
                    && not_chars.find(std::get<1>(trans)) == not_chars.end() )
                    {
                        // std::cout << "Adding " << i << " -"  << std::get<1>(trans) << "-> " << dest << std::endl;
                        new_transitions.emplace_back(TransitionType::CHAR, std::get<1>(trans), dest);
                    }
                }
                new_transitions.emplace_back(TransitionType::ANY, '@', dest);
            }
        }
        nfa_node.transitions.insert( nfa_node.transitions.end(), new_transitions.begin(), new_transitions.end() );
        
        // Replace NOT_CHAR with ANY transition, and add transition to a dead state on the not character.
        for(size_t i = 0; i != original_transition_count; i++)
        {
            Transition& trans = nfa_node.transitions[i];

            if(std::get<0>(trans) == TransitionType::NOT_CHAR)
            {
                nfa_node.transitions.emplace_back(TransitionType::CHAR, std::get<1>(trans), nfa.size());

                std::get<0>(trans) = TransitionType::ANY;
                std::get<1>(trans) = '@'; // For debug
            }
        }
    }

    // Add a reject state at the end of the NFA
    nfa.emplace_back(NFANode(false));

    // For debug
    // std::cout << std::endl << "After ANY and NOT_CHAR adjustments..." << std::endl;
    // printNFA(nfa);
    
    // For each NFA node
    while(!new_states.empty())
    {
        std::set<size_t> closure = new_states.front();
        new_states.pop();
        
        // TODO replace all char with typedef
        std::map<char, std::set<size_t>> char_trans;
        std::set<size_t> any_trans;

        // Create map of all the states each char transitions to
        for(size_t nfa_node: closure)
        {
            for(const Transition& trans: nfa[nfa_node].transitions)
            {
                // std::cout << std::get<1>(trans) << " -> " <<  std::get<2>(trans) << ", ";

                // TODO Find all other elements that go to same set
                if(std::get<0>(trans) == TransitionType::ANY)
                {
                    any_trans.insert(closures[std::get<2>(trans)].begin(), closures[std::get<2>(trans)].end());
                }
                else if(std::get<0>(trans) == TransitionType::CHAR)
                {
                    char_trans[std::get<1>(trans)].insert(closures[std::get<2>(trans)].begin(), closures[std::get<2>(trans)].end());
                }
            }
        }

        // For each char transition, take the set it maps to and add that to our dfa 
        for(auto const& [character, state] : char_trans)
        {
            // std::cout << character << ": ";
            // for(auto e: state) std::cout << e << ", ";
            // std::cout << std::endl;

            if(dfa_states.find(state) == dfa_states.end())
            {
                dfa_states.insert({state, dfa.size()});
                dfa.emplace_back(isAccept(nfa, state));
                dfa.back().rule = minRule(nfa, state);
                new_states.push(state);
            }

            dfa[dfa_states[closure]].transitions.emplace_back(TransitionType::CHAR, character, dfa_states[state]);
        }

        if(any_trans.size() > 0)
        {
            if(dfa_states.find(any_trans) == dfa_states.end())
            {
                dfa_states.insert({any_trans, dfa.size()});
                dfa.emplace_back(isAccept(nfa, any_trans));
                dfa.back().rule = minRule(nfa, any_trans);
                new_states.push(any_trans);
            }

            dfa[dfa_states[closure]].transitions.emplace_back(TransitionType::ANY, 0, dfa_states[any_trans]);
        }
    }

    return dfa;
}

void printNFA(const NFA& nfa)
{
    for(size_t i = 0; i != nfa.size(); i++)
    {
        if(nfa[i].accept)
        {
            std::cout << i << " accept " << nfa[i].rule << std::endl;
        }
        else
        {
            std::cout << i << std::endl;
        }

        for(const Transition& trans: nfa[i].transitions)
        {
            std::cout << "\t" << std::get<1>(trans) << " -> " << std::get<2>(trans) << std::endl;
        }
    }
}

void generateWorkingDFA(const NFA& dfa, const std::vector<std::pair<RegexNode, std::string>>& rules, std::ofstream& out)
{
    // Only generate code for possibly reachable states
    // This doesn't trim all unreachable states
    std::set<size_t> possibly_reachable;
    possibly_reachable.insert(0);
    for(const NFANode& nfa_node: dfa)
    {
        for(const Transition& trans: nfa_node.transitions)
        {
            possibly_reachable.insert(std::get<2>(trans));
        }
    }

    out << "#include <utility>\n"
           "#include <iostream>\n"
           "const std::pair<TokenType, long> longestPrefixRecognize(size_t start, const std::string &s)\n"
           "{\n"
           "std::pair<TokenType, long> last_accepted(REJECT, -1);\n\n"
           ;

    for(size_t state = 0; state != dfa.size(); state++)
    {
        if(possibly_reachable.find(state) != possibly_reachable.end())
        {
            out << "S_" << state << ":\n";
            // Uncomment to print path of DFA
            // out << "std::cout << " << state << " << std::endl;\n";

            if(dfa[state].accept) out << "last_accepted = {" << rules[dfa[state].rule].second << ",start};\n";

            if(state != 0)
            {
                out << "start++;\n";
                out << "if(start >= s.size()) { last_accepted.second++; return last_accepted; }\n";
            }

            out << "switch(s[start])\n"
                   "{\n";

            bool any_found = false;
            size_t any_trans;
            for(const Transition& trans: dfa[state].transitions)
            {
                if(std::get<0>(trans) == TransitionType::ANY)
                {
                    assert(!any_found);
                    any_found = true;
                    any_trans = std::get<2>(trans);
                }
                else if(std::get<0>(trans) == TransitionType::CHAR)
                {
                    out << "\tcase '";

                    // Escape character if neccessary
                    switch(std::get<1>(trans))
                    {
                        case '\n': out << "\\n"; break;
                        case '\r': out << "\\r"; break;
                        case '\t': out << "\\t"; break;
                        case '\v': out << "\\v"; break;
                        case '\f': out << "\\f"; break;
                        case '\0': out << "\\0"; break;
                        default: out << std::get<1>(trans); break;
                    }

                    out << "': goto S_" << std::get<2>(trans) << ";\n";
                }
            }

            // Create default statement
            if(any_found)
            {
                out << "\tdefault: goto S_" << any_trans << ";\n";
            }
            else
            {
                out << "\tdefault: last_accepted.second++; return last_accepted;\n";
            }
                   
            out << "}\n\n";       
        }
    }

    out << "}" << std::endl;
}

void populateRules(NFA& nfa, int rule)
{
    for(NFANode& nfa_node: nfa)
    {
        if(nfa_node.accept) nfa_node.rule = rule;
    }
}
