#include "Machine.h"
#include "Head.h"
#include "ExampleConfig.h"

Machine::Machine(){}

void Machine::processTape(vector<char> tape) {//magic happens here
    int currentStateIndex = 1; //we start on one so we don't fail hella fast sitting on a blank character
    string currentState = "";
    bool halted = false;
    int iterationCounter = 1;
    Head tmHead;
    ExampleConfig tmConfig;
    
    currentState = (tmConfig.getSetOfStates())[0]; //get the initial state from the example configuration

    while (!halted) {
        char tapeCharacter = tape[currentStateIndex];

        if (currentState.compare(tmConfig.getAcceptState()) == 0) {

            halted = true;
            tape.push_back('#');//a little hacky but valid            
            printTape(tape, iterationCounter, currentStateIndex, currentState);

        } else if (currentState.compare(tmConfig.getRejectState()) == 0) {

            halted = true;
            tape.push_back('#');//hax
            printTape(tape, iterationCounter, currentStateIndex, currentState);

        } else {

            printTape(tape, iterationCounter, currentStateIndex, currentState);
            TransitionFunction* transFunc = tmConfig.getTransitionFunction(currentState, tapeCharacter);

            if ( transFunc != NULL ) {//ayuup, we found the Transition function goods
                if ((transFunc->writeSymbol) != ' ') {//blank character's don't write ish
                    tape[currentStateIndex] = transFunc->writeSymbol;
                }
                
                switch (transFunc->headDirection) {
                    case LEFT:
                        currentStateIndex--; //go backwards on the tape
                        break;
                    case RIGHT:
                        currentStateIndex++; //go forwards on the tape
                        break;
                }

                currentState = transFunc->nextState;//hey, I just met you, and this is crazy, but can this next state be accept, maybe?
 
            } else { // oh crap, we're here because given the current state and tape character, there are no transitions to other states. #rejected
                halted = true;  
                cout << "transition not found" << endl;
            }
        }
        iterationCounter++; 
    }
}


void Machine::printTape(vector<char> tape, int iterationCounter, int stateIndex, string state) {
    printf("%i: ", iterationCounter);     

    for (int i = 1; i < tape.size(); i++) {
        if (i == stateIndex) {
            printf("%s ", state.c_str());
        } else {
            printf("%c ", tape[i]);

        }
    }
    
    printf("\n");
}
