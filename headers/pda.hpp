#pragma once

#include <map>
#include <string>
#include <deque>

#include "headers/alphabet.hpp"
#include "headers/state.hpp"

// PDA stands for PushDown Automaton.
class PDA {
    protected:
    Alphabet tape_alphabet;
    Alphabet stack_alphabet;
    std::map<std::string, State> states;
    std::string initial_state;
    char initial_stack_token;
    
    public: 
    PDA(
        Alphabet tape_alphabet,
        Alphabet stack_alphabet,
        std::map<std::string, State> states,
        std::string initial_state,
        char initial_stack_token
    );
    virtual ~PDA();
    virtual bool check_string(const std::string& s) const;
    
    protected:
    virtual bool check_string(const std::string& s, const std::string& actual_state, std::deque<char> stack) const;
};