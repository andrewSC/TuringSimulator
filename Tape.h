#include <string>
#include <vector> 

using namespace std;

class Tape {

    public:
        Tape(string inputTape);
        void setTape(string inputTape);
        vector<char> getTape();

    private:
        string tape;
};
