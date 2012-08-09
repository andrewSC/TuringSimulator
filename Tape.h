#include <string>
#include <vector> 

using namespace std;

class Tape {

    public:
        Tape(string inputTape);
        void setTape(vector<char> inputTape);
        vector<char> getTape();

    private:
        vector<char> tape;
};
