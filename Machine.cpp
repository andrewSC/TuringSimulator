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
        printTape(tape, iterationCounter, currentStateIndex, currentState);
        char tapeCharacter = tape[currentStateIndex];

       TransitionFunction* transFunc = tmConfig.getTransitionFunction(currentState, tapeCharacter);
    
        if ( transFunc != NULL ) {//ayuup, we found the Transition function goods
            if ((transFunc->headDirection) != STAY) {//ayup, can't stop won't stop

                if ((transFunc->writeSymbol) != ' ') {//if i got a blank character it means don't write ish
                    tape[currentStateIndex] = transFunc->writeSymbol; //write the symbol to the tape
                }
                
                switch (transFunc->headDirection) {
                    case LEFT:
                        currentStateIndex--; //go backwards on the tape
                        break;
                    case RIGHT:
                        currentStateIndex++; //go forwards on the tape
                        break;
                }

                currentState = transFunc->nextState;//hey, I just met you, and this is crazy, but this next state is accept, maybe?
 
            } else {//apparently we either accepted or rejected, coolio.
                halted = true;
            }      

 
        } else { // oh crap
            halted = true;
            cout << "not good bro" << endl;
        }

        iterationCounter++; 
    }
}


void Machine::printTape(vector<char> tape, int iterationCounter, int stateIndex, string state) {
    printf("%i: ", iterationCounter);     

    for (int i = 1; i < tape.size(); i++) {
        if (i == stateIndex) {
            printf("%s", state.c_str());
        } else {
            printf("%c", tape[i]);

        }
    }
    
    printf("\n");
}
