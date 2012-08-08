#include <string>
#include "Direction.h"

using namespace std;

class State {
    public:
        State();
        State(string symbolToWrite, int direction);
        void setNextState(State& nextStateTransition);
        State& getNextState();
        void setWriteSymbol(string symbolToWrite);
        string getWriteSymbol();
        void setHeadDirection(int direction);
        int getHeadDirection();

    private:
        State* nextState;
        string writeSymbol;
        int headDirection;
}; 
