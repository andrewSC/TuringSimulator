#include "Head.h"


void Head::processInputString(vector<char> tape) {
    int currentIndex;
    bool halted = false;
    int iterationCounter = 0;
    
    
    while(!halted) {
        printTape(tape, iterationCounter);
        char characterReadOnTape = tape[currentIndex];
        


    }
}


void Head::printTape(vector<char> tape, int iterationCounter) {
    
    printf("%i: ", iterationCounter);    

    for(int i = 0; i < tape.size(); i++) {
        printf("%c", tape[i]);
    }
    
    printf("\n");
}
