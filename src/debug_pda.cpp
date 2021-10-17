#include "headers/debug_pda.hpp"

using std::vector;
using std::string;
using std::deque;
using std::map;
using std::cout;
using std::setw;
using std::to_string;

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
    cout << setw(3) << "ID" << SEPARATOR;
    cout << setw(6) << "State" << SEPARATOR;
    cout << setw(11) << "Tape token" << SEPARATOR;
    cout << setw(12) << "Stack token" << SEPARATOR;
    cout << setw(12) << "Destination" << SEPARATOR;
    cout << setw(17) << "New stack tokens" << "\n";
    print_vertical_separator(65);
    for (auto state : states) {
        for (auto transition : state.second.get_transitions()) {
            print_transition(transition, state.first);
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

void DebugPDA::print_vertical_separator(int width) const {
    for (int i = 0; i < width; i++) {
        cout << SEPARATOR;
    }
    cout << "\n";
}

void DebugPDA::print_transition(const Transition& transition, const string& state_name) const {
   cout << std::right;
   cout << setw(2) << transition.get_id() << " " << SEPARATOR;
   cout << setw(5) << state_name << " " << SEPARATOR;
   cout << setw(10) << transition.get_tape_token() << " " << SEPARATOR;
   cout << setw(11) << transition.get_stack_token() << " " << SEPARATOR;
   cout << setw(11) << transition.get_destination() << " " << SEPARATOR;
   string new_stack_tokens;
   for (auto token : transition.get_new_stack_tokens()) {
       new_stack_tokens += token;
   }
   cout << setw(16) << new_stack_tokens << " " ;
   cout << "\n";
}

bool DebugPDA::check_string(const string& s) const {
    cout << "\nTrace:\n";
    cout << std::left;
    cout << setw(10) << "State" << SEPARATOR;
    cout << setw(15) << "String" << SEPARATOR;
    cout << setw(15) << "Stack" << SEPARATOR;
    cout << setw(12) << "Transitions" << "\n";
    print_vertical_separator(54);
    return PDA::check_string(s);
}

bool DebugPDA::check_string(const string& s, const string& actual_state_name, deque<char> stack) const {
    cout << std::right;
    cout << setw(9) << actual_state_name << " " << SEPARATOR;
    cout << setw(14) << s << " " << SEPARATOR;
    string stack_output;
    for (auto token : stack) {
        stack_output += token;
    }
    cout << setw(14) << stack_output << " " << SEPARATOR;
    vector<Transition> transitions = 
        states.at(actual_state_name).get_valid_transitions(s[0], stack.front());
    string transitions_output;
    for (auto transition : transitions) {
        transitions_output += to_string(transition.get_id());
    }
    cout << setw(11) << transitions_output << "\n";
    return PDA::check_string(s, actual_state_name, stack);
}