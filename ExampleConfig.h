#include <vector>
#include <map>
#include <string>

#include "Direction.h"

using namespace std;

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
        TransitionFunction* getTransitionFunction(string state, char tapeCharacter);
        string getStartState();
        string getAcceptState();
        string getRejectState();

    private:
        void setSetOfStates();
        vector<string> setOfStates;
        
};

