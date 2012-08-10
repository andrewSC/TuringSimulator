#include <vector>
#include <string>
#include <stdio.h>


using namespace std;

class Machine {
    public:
        Machine();
        void processTape(vector<char> tape);
        void printTape(vector<char> tape, int iterationCounter, int stateIndex, string state);        
};
