#include "ExampleConfig.h"


struct transitionFunction {
    char writeSymbol;
    int headDirection;
    string nextState;
};

typedef map<char, transitionFunction> functionLookupTable;


vector<string> ExampleConfig::getSetOfStates() {
    vector<string> setOfStates(7);
  
    setOfStates[0] = "q1";
    setOfStates[1] = "q2";
    setOfStates[2] = "q3";
    setOfStates[3] = "q4";
    setOfStates[4] = "q5";
    setOfStates[5] = "q_accept";
    setOfStates[6] = "q_reject";

    return setOfStates;
}


vector<string> ExampleConfig::getInputAlphabet() {
    vector<string> inputAlphabet(1);

    inputAlphabet[0] = "0";        

    return inputAlphabet; 
}


vector<string> ExampleConfig::getTapeAlphabet() {
    vector<string> tapeAlphabet(3);
    
    tapeAlphabet[0] = "0";
    tapeAlphabet[1] = "x";
    tapeAlphabet[2] = "#";

    return tapeAlphabet;
}


void ExampleConfig::getTransitionFunction() {
    map<string, functionLookupTable> transitionLookupTable;

    
    
}
