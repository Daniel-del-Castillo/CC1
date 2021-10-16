#include "headers/transition.hpp"

using std::string;
using std::vector;

Transition::Transition(
    std::string destination,
    char tape_token,
    char stack_token,
    vector<char> new_stack_tokens
) : destination(destination),
    tape_token(tape_token),
    stack_token(stack_token),
    new_stack_tokens(new_stack_tokens) {}

string Transition::get_destination() const {
    return destination;
}

vector<char> Transition::get_new_stack_tokens() const {
    return new_stack_tokens;
}

bool Transition::is_valid_transition(char tape_token, char stack_token) const {
    return tape_token == this->tape_token && stack_token == this->tape_token;
}