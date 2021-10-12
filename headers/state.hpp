#pragma once

#include <vector>

#include "headers/transition.hpp"

class State {
    std::vector<Transition> transitions;
};