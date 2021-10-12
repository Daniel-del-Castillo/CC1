#pragma once

#include <set>
#include <stack>
#include <string>

#include "headers/alphabet.hpp"
#include "headers/state.hpp"

class PushdownAutomaton {
    Alphabet tape_alphabet;
    Alphabet stack_alphabet;
    std::set<State> states;
    std::string initial_state;
    std::string initial_stack_token;
};