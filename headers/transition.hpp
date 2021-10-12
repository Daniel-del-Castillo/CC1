#pragma once

#include <string>
#include <vector>

class Transition {
    std::string destination;  
    std::string stack_token;
    std::string tape_token;
    std::vector<std::string> new_stack_tokens;
};