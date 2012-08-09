#include "Tape.h"

Tape::Tape(string inputTape) {
    vector<char> tapeVector(inputTape.length());   
    tapeVector.assign(tape.begin(), tape.end());
    tape = tapeVector;
}

void Tape::setTape(vector<char> inputTape) {
    tape = inputTape;
}

vector<char> Tape::getTape() {
    return tape;
}
