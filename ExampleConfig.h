#include <vector>
#include "State.h"

class ExampleConfig {
    
    public:
        vector<string> getSetOfStates();
        vector<string> getInputAlphabet();
        vector<string> getTapeAlphabet();
        vector<State> getTransitionFunction();
        string getStartState();
        string getAcceptState();
        string getRejectState();
};

