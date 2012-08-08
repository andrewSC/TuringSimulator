#include <vector>
#include <stdio.h>

#include "State.h"
#include "Tape.h"

class Head {
    public:
        void processInputString(vector<char> tape);
        void printTape(vector<char> tape, int iterationCounter);    
};
