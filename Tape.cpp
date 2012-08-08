#include "Tape.h"

Tape::Tape(string inputTape) {
    setTape(inputTape);
}

void Tape::setTape(string inputTape) {
    tape = inputTape;
}

vector<char> Tape::getTape() {
    vector<char> tapeVector(tape.length() + 1);
       
    tapeVector.assign(tape.begin(), tape.end());
    tapeVector.back() = '\0';

    return tapeVector;
}
