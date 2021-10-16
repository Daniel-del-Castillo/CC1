#pragma once

#include <string>
#include <vector>

class Transition {
    std::string destination;  
    char stack_token;
    char tape_token;
    std::vector<char> new_stack_tokens;
    
    public:
    Transition(
        std::string destination,
        char stack_token,
        char tape_token,
        std::vector<char> new_stack_tokens
    );
};