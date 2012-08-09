#include <vector>
#include <map>

#include "State.h"

class ExampleConfig {
    public:
        ExampleConfig();
        vector<string> getSetOfStates();
        vector<string> getInputAlphabet();
        vector<string> getTapeAlphabet();
        void getTransitionFunction();
        string getStartState();
        string getAcceptState();
        string getRejectState();
};

