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
    is_backtracking = false;
    cout << BLUE << "Q: " << states_to_string(states) << "\n"; 
    cout << BLUE << "Σ: " << alphabet_to_string(tape_alphabet) << "\n"; 
    cout << BLUE << "Γ: " << alphabet_to_string(stack_alphabet) << "\n"; 
    cout << BLUE << "S: " << YELLOW << initial_state << "\n"; 
    cout << BLUE << string("Z: ") << YELLOW << initial_stack_token << "\n"; 
    cout << BLUE << "δ:\n"; 
    cout << std::left;
    cout << BLUE << setw(3) << "ID" << GREEN << SEPARATOR;
    cout << BLUE << setw(6) << "State" << GREEN << SEPARATOR;
    cout << BLUE << setw(11) << "Tape token" << GREEN << SEPARATOR;
    cout << BLUE << setw(12) << "Stack token" << GREEN << SEPARATOR;
    cout << BLUE << setw(12) << "Destination" << GREEN << SEPARATOR;
    cout << BLUE << setw(17) << "New stack tokens" << RESET_COLOR << "\n";
    print_vertical_separator(65);
    for (auto state : states) {
        for (auto transition : state.second.get_transitions()) {
            print_transition(transition, state.first);
        }
    }
}

string DebugPDA::states_to_string(const map<string, State>& states) const {
    string result = string(GREEN) + "{ "; 
    for (auto name_state_pair : states) {
        result += YELLOW + name_state_pair.first + GREEN + ", ";
    }
    result = result.substr(0, result.size() - 2) + " }";
    return result;
}

string DebugPDA::alphabet_to_string(const Alphabet& alphabet) const {
    string result = string(GREEN) + "{ "; 
    for (auto token : alphabet.get_tokens()) {
        result += string(YELLOW) + token + string(GREEN) + ", ";
    }
    result = result.substr(0, result.size() - 2) + " }";
    return result;
}

void DebugPDA::print_vertical_separator(int width) const {
    cout << GREEN;
    for (int i = 0; i < width; i++) {
        cout << SEPARATOR;
    }
    cout << RESET_COLOR << "\n";
}

void DebugPDA::print_transition(const Transition& transition, const string& state_name) const {
   cout << std::right;
   cout << RED << setw(2) << transition.get_id() << " " << GREEN << SEPARATOR;
   cout << YELLOW << setw(5) << state_name << " " << GREEN << SEPARATOR;
   cout << YELLOW << setw(10) << transition.get_tape_token() << " " << GREEN << SEPARATOR;
   cout << YELLOW << setw(11) << transition.get_stack_token() << " " << GREEN << SEPARATOR;
   cout << YELLOW << setw(11) << transition.get_destination() << " " << GREEN << SEPARATOR;
   string new_stack_tokens;
   for (auto token : transition.get_new_stack_tokens()) {
       new_stack_tokens += token;
   }
   cout << YELLOW << setw(16) << new_stack_tokens << RESET_COLOR << " \n";
}

bool DebugPDA::check_string(const string& s) const {
    cout << BLUE << "\nTrace:\n";
    cout << std::left;
    cout << BLUE << setw(10) << "State" << GREEN << SEPARATOR;
    cout << BLUE << setw(15) << "String" << GREEN << SEPARATOR;
    cout << BLUE << setw(15) << "Stack" << GREEN << SEPARATOR;
    cout << BLUE << setw(12) << "Transitions" << RESET_COLOR << "\n";
    print_vertical_separator(54);
    return PDA::check_string(s);
}

bool DebugPDA::check_string(const string& s, const string& actual_state_name, deque<char> stack) const {
    is_backtracking = false;
    cout << std::right;
    cout << YELLOW << setw(9) << actual_state_name << " " << GREEN << SEPARATOR;
    cout << YELLOW << setw(14) << s << " " << GREEN << SEPARATOR;
    string stack_output;
    for (auto token : stack) {
        stack_output += token;
    }
    cout << YELLOW << setw(14) << stack_output << " " << GREEN << SEPARATOR;
    vector<Transition> transitions = 
        states.at(actual_state_name).get_valid_transitions(s[0], stack.front());
    string transitions_output;
    for (auto transition : transitions) {
        transitions_output += to_string(transition.get_id()) + " ";
    }
    cout << RED << setw(11) << transitions_output << RESET_COLOR << "\n";
    bool result = PDA::check_string(s, actual_state_name, stack);
    if (!result && !is_backtracking) {
        print_vertical_separator(54); // Print a vertical separator when a branch ends
        is_backtracking = true; 
    }
    return result;
}