#include "headers/alphabet.hpp"

using std::vector;

Alphabet::Alphabet() {}

Alphabet::Alphabet(vector<char> tokens) {
    for (char token: tokens) {
        add_token(token);
    }
}

void Alphabet::add_token(char token) {
    tokens.insert(token);
}

bool Alphabet::contains(char token) const {
    return tokens.count(token) == 1;
}