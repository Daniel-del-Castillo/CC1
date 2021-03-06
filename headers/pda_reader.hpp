#pragma once

#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>

#include "headers/pda.hpp"
#include "headers/debug_pda.hpp"
#include "headers/state.hpp"
#include "headers/alphabet.hpp"

// Allows reading a PDA from a file. The PDA can be a DebugPDA or PDA
// depending on a debug flag
class PDAReader {
    Alphabet tape_alphabet;
    Alphabet stack_alphabet;
    std::map<std::string, State> states; 

    public:
    static PDA* read_pda(std::istream& input, bool debug);
    PDA* read_pda_from_stream(std::istream& input, bool debug);
    
    private:
    std::string read_line(std::istream& input);
    std::map<std::string, State> read_states(const std::string& line);
    Alphabet read_alphabet(const std::string& line);
    std::string read_initial_state(const std::string& line);
    char read_initial_stack_token(const std::string& line);
    void add_transitions(std::istream &input);
    void add_transition(const std::string& line, int id);
    std::vector<std::string> split_whitespace(const std::string& line);
};

