#include <iostream>
#include <fstream>
#include <string>

#include "headers/pda_reader.hpp"

using std::ifstream;
using std::cout;
using std::string;
using std::cin;

struct Args {
    std::string definition_file;
    std::string strings_file;
    bool debug;
    
    Args(int argc, char** argv) {
        for (int i = 1; i < argc; i++) {
            if (string(argv[i]) == "-d") {
                debug = true;
                continue;
            }
            if (definition_file.empty()) {
                definition_file = argv[i];
            } else {
                strings_file = argv[i];
            }
        }
    }
};

void print_help() {
    cout << "This program allows emulating the behaviour of a pushdown automaton (PDA) that accepts by empty state\n";
    cout << "The first argument must be the path to a file where a valid PDA definition is stored\n";
    cout << "The second argument is optional and should be a file in which each line will be evaluated by the PDA\n";
    cout << "If this argument isn't specified, the string will be read from the command line and \"exit\" will be reserved to exit the program\n";
    cout << "It is also possible to specify the -d option which allows printing debug information\n";
}

int main(int argc, char** argv) {
    if (argc < 2 || argc > 4) {
        print_help();
        return 0;
    }
    Args args(argc, argv);
    if (args.definition_file.empty()) {
        print_help();
        return 0;
    }

    ifstream input_file(args.definition_file);
    PDA* pda = PDAReader::read_pda(input_file, args.debug);
    string s;
    while (true) {
        getline(cin, s);
        if (s == "exit") {
            break;
        }
        if (pda->check_string(s)) {
            cout << "The string " + s + " belongs to the language\n";
        } else {
            cout << "The string " + s + " doesn't belong to the language\n";
        }
    }
    free(pda);
}