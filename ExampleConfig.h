#include <vector>

class ExampleDef {
    
    public:
        vector<string> getSetOfStates();
        vector<string> getInputAlphabet();
        vector<string> getTapeAlphabet();
        vector<string> getTransitionFunction();
        string getStartState();
        string getAcceptState();
        string getRejectState();
};

