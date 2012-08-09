#include "Machine.h"

Machine::Machine(){}

void Machine::processTape(vector<char> tape) {
    int currentIndex;
    bool halted = false;
    int iterationCounter = 0;
    
    
    while(!halted) {
        printTape(tape, iterationCounter);
        char characterReadOnTape = tape[currentIndex];
        


    } 
}


void Machine::printTape(vector<char> tape, int iterationCounter) {
    printf("%i: ", iterationCounter);    

    for(int i = 0; i < tape.size(); i++) {
        printf("%c", tape[i]);
    }
    
    printf("\n");
}
