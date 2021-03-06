#include "Tape.h"
#include "ExampleConfig.h"
#include <iostream>

Tape::Tape(string inputTape) {
    ExampleConfig conf;
    vector<char> tapeVector;
   
    tapeVector.push_back((conf.getTapeAlphabet()).back());
    for (int i = 0; i < inputTape.length(); i++) {
        tapeVector.push_back(inputTape[i]);
    }
    tapeVector.push_back((conf.getTapeAlphabet()).back());// extra padding, yo
    
    tape = tapeVector;
}

void Tape::setTape(vector<char> inputTape) {
    tape = inputTape;
}

vector<char> Tape::getTape() {
    return tape;
} 
