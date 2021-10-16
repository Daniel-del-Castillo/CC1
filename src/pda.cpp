#include "headers/pda.hpp"

using std::map;
using std::string;

PDA::PDA(
    Alphabet tape_alphabet,
    Alphabet stack_alphabet,
    map<string, State> states,
    string initial_state,
    char initial_stack_token
):
    tape_alphabet(tape_alphabet),
    stack_alphabet(stack_alphabet),
    states(states),
    initial_state(initial_state),
    initial_stack_token(initial_stack_token) {}