#pragma once

#include <string>
#include <deque>
#include <map>
#include <iostream>
#include <iomanip>

#include "headers/alphabet.hpp"
#include "headers/pda.hpp"

#define SEPARATOR "█"
#define RED "\x1B[91m"
#define GREEN "\x1B[92m"
#define BLUE "\x1B[94m"
#define YELLOW "\x1B[93m"
#define RESET_COLOR "\033[0m"

// This class contains all the code related to debugging and printing
// traces of the execution. It relies on the PDA class for the actual emulation
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