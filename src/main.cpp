#include <iostream>
#include <fstream>
#include <string>

#include "headers/pda_reader.hpp"

using std::ifstream;
using std::cout;
using std::string;

void print_help() {
    cout << "This program allows emulating the behaviour of a pushdown automaton (PDA) that accepts by empty state\n";
    cout << "The first argument must be the path to a file where a valid PDA definition is stored\n";
    cout << "The second argument is optional and should be a file in which each line will be evaluated by the PDA\n";
    cout << "If this argument isn't specified, the string will be read from the command line\n";
    cout << "It is also possible to specify the -d option which allows printing debug information\n";
}

int main(int argc, char** argv) {
    if (argc < 2 || argc > 4) {
        print_help();
        return 0;
    }
    std::string definition_file;
    std::string strings_file;
    // bool debug = false;
    for (int i = 1; i < argc; i++) {
        if (string(argv[i]) == "-d") {
            // debug = true;
            continue;
        }
        if (definition_file.empty()) {
            definition_file = argv[i];
        } else {
            strings_file = argv[i];
        }
    }
    if (definition_file.empty()) {
        print_help();
        return 0;
    }

    ifstream input_file(definition_file);
    PDA pda = PDAReader::read_pda(input_file);
    cout << pda.check_string("ab");
}