#include <vector>
#include <string>

using namespace std;

class Head {
    public:
        Head();
        void processTapeCharacter(char tape);
        void setCurrentState(string newState);
        string getCurrentState();
    
    private:
        string currentState;
};
