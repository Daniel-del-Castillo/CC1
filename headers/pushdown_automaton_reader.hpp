#pragma once

#include <fstream>

#include "headers/pushdown_automaton.hpp"

class PushdownAutomatonReader {
    public:
    PushdownAutomatonReader();
    PushdownAutomaton read_automaton(std::istream& input);
};

