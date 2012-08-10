#include <vector>
#include <map>

#include "State.h"

struct TransitionFunction {
    char writeSymbol;
    int headDirection;
    string nextState;
};

class ExampleConfig {
    public:
        ExampleConfig();
        vector<string> getSetOfStates();
        vector<string> getInputAlphabet();
        vector<string> getTapeAlphabet();
        TransitionFunction getTransitionFunction(string state, char tapeCharacter);
        string getStartState();
        string getAcceptState();
        string getRejectState();
        
};

