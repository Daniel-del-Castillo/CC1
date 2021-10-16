#pragma once

#include <string>
#include <vector>

class Transition {
    std::string destination;  
    char tape_token;
    char stack_token;
    std::vector<char> new_stack_tokens;
    
    public:
    Transition(
        std::string destination,
        char tape_token,
        char stack_token,
        std::vector<char> new_stack_tokens
    );
    std::string get_destination() const;
    std::vector<char> get_new_stack_tokens() const;
    bool is_valid_transition(char tape_token, char stack_token) const;
};