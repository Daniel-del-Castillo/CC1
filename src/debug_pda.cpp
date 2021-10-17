#include "headers/debug_pda.hpp"

using std::vector;
using std::string;
using std::deque;
using std::map;
using std::cout;
using std::setw;

DebugPDA::DebugPDA(
    Alphabet tape_alphabet,
    Alphabet stack_alphabet,
    map<string, State> states,
    string initial_state,
    char initial_stack_token
) : PDA(tape_alphabet, stack_alphabet, states, initial_state, initial_stack_token) {
    cout << "Q: " + states_to_string(states) + "\n"; 
    cout << "Σ: " + alphabet_to_string(tape_alphabet) + "\n"; 
    cout << "Γ: " + alphabet_to_string(stack_alphabet) + "\n"; 
    cout << "S: " + initial_state + "\n"; 
    cout << string("Z: ") + initial_stack_token + "\n"; 
    cout << "δ:\n"; 
    cout << std::left;
    cout << setw(3) << "ID" << VERTICAL_SEPARATOR;
    cout << setw(6) << "State" << VERTICAL_SEPARATOR;
    cout << setw(11) << "Tape token" << VERTICAL_SEPARATOR;
    cout << setw(12) << "Stack token" << VERTICAL_SEPARATOR;
    cout << setw(12) << "Destination" << VERTICAL_SEPARATOR;
    cout << setw(17) << "New stack tokens" << VERTICAL_SEPARATOR << "\n";
    print_horizontal_separator();
    for (auto state : states) {
        for (auto transition : state.second.get_transitions()) {
           cout << std::right;
           cout << setw(2) << transition.get_id() << " " << VERTICAL_SEPARATOR;
           cout << setw(5) << state.first << " " << VERTICAL_SEPARATOR;
           cout << setw(10) << transition.get_tape_token() << " " << VERTICAL_SEPARATOR;
           cout << setw(11) << transition.get_stack_token() << " " << VERTICAL_SEPARATOR;
           cout << setw(11) << transition.get_destination() << " " << VERTICAL_SEPARATOR;
           string new_stack_tokens;
           for (auto token : transition.get_new_stack_tokens()) {
               new_stack_tokens += token;
           }
           cout << setw(16) << new_stack_tokens << " " << VERTICAL_SEPARATOR;
           cout << "\n";
        }
    }

}
string DebugPDA::states_to_string(const map<string, State>& states) const {
    string result = "{ "; 
    for (auto name_state_pair : states) {
        result += name_state_pair.first + ", ";
    }
    result = result.substr(0, result.size() - 2);
    result += " }";
    return result;
}

string DebugPDA::alphabet_to_string(const Alphabet& alphabet) const {
    string result = "{ "; 
    for (auto token : alphabet.get_tokens()) {
        result += token + string(", ");
    }
    result = result.substr(0, result.size() - 2);
    result += " }";
    return result;
}

void DebugPDA::print_horizontal_separator() const {
    for (int i = 0; i < 70; i++) {
        cout << HORIZONTAL_SEPARATOR;
    }
    cout << "\n";
}

bool DebugPDA::check_string(const string& s) const {
    return PDA::check_string(s);
}

bool DebugPDA::check_string(const string& s, const string& actual_state_name, deque<char> stack) const {
    return PDA::check_string(s, actual_state_name, stack);
}