#pragma once

#include <string>
#include <deque>
#include <map>
#include <iostream>
#include <iomanip>

#include "headers/alphabet.hpp"
#include "headers/pda.hpp"

#define SEPARATOR "█"

// PDA stands for PushDown Automaton
class DebugPDA : PDA {
    mutable bool is_backtracking;
    public: 
    DebugPDA(
        Alphabet tape_alphabet,
        Alphabet stack_alphabet,
        std::map<std::string, State> states,
        std::string initial_state,
        char initial_stack_token
    );
    bool check_string(const std::string& s) const override;
    
    protected:
    bool check_string(
        const std::string& s,
        const std::string& actual_state,
        std::deque<char> stack
    ) const override;
    std::string states_to_string(const std::map<std::string, State>& states) const;
    std::string alphabet_to_string(const Alphabet& alphabet) const;
    void print_vertical_separator(int width) const;
    void print_transition(const Transition& transition, const std::string& state_name) const;
};