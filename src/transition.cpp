#include "headers/transition.hpp"

Transition::Transition(
    std::string destination,
    char stack_token,
    char tape_token,
    std::vector<char> new_stack_tokens
) : destination(destination),
    stack_token(stack_token),
    tape_token(tape_token),
    new_stack_tokens(new_stack_tokens) {}