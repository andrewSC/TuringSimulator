#include "Machine.h"
#include "Head.h"
#include "ExampleConfig.h"

Machine::Machine(){}

void Machine::processTape(vector<char> tape) {//magic happens here
    int currentStateIndex = 0;
    string currentState = "";
    bool halted = false;
    int iterationCounter = 1;
    Head tmHead;
    ExampleConfig tmConfig;
    
    currentState = (tmConfig.getSetOfStates())[0]; //get the initial state from the example configuration
    
    while(!halted) {
        printTape(tape, iterationCounter, currentStateIndex, currentState);
        char tapeCharacter = tape[currentStateIndex];

       TransitionFunction* transFunc = tmConfig.getTransitionFunction(currentState, tapeCharacter);
    
        if( transFunc == NULL ) {
            //we've failed, oh lawdy, now wut
        }

        iterationCounter++; 
    } 
}


void Machine::printTape(vector<char> tape, int iterationCounter, int stateIndex, string state) {
    printf("%i: ", iterationCounter);    

    for(int i = 0; i < tape.size(); i++) {
        if(i == stateIndex) {
            printf("%s", state.c_str());
        } else {
            printf("%c", tape[i]);

        }
    }
    
    printf("\n");
}
