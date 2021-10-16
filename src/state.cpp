#include "headers/state.hpp"

State::State() {}

void State::add_transition(Transition transition) {
   transitions.push_back(transition);
}