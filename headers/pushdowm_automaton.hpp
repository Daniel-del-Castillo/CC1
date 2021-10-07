#pragma once

#include <vector>

#include "alphabet.hpp"

class PushdownAutomaton {
    Alphabet tape_alphabet;
    Alphabet stack_alphabet;
    std::vector<State> states;
}