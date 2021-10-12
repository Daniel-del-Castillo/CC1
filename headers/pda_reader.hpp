#pragma once

#include <fstream>

#include "headers/pda.hpp"

class PushdownAutomatonReader {
    public:
    PushdownAutomatonReader();
    PushdownAutomaton read_automaton(std::istream& input);
};

