#include "ExampleConfig.h"

typedef map<char, TransitionFunction> functionLookupTable;
map<string, functionLookupTable> transitionLookupTable;

ExampleConfig::ExampleConfig() {
    //q1
    functionLookupTable q1_functionTable;
    vector<TransitionFunction> q1_partialTransition(3);
        //q1 on 0
        q1_partialTransition[0].writeSymbol = '#';
        q1_partialTransition[0].headDirection = RIGHT;
        q1_partialTransition[0].nextState = "q2";

        //q1 on x
        q1_partialTransition[1].writeSymbol = ' '; //we don't write anything to the tape
        q1_partialTransition[1].headDirection = RIGHT;
        q1_partialTransition[1].nextState = "q_reject";

        //q1 on #
        q1_partialTransition[2]. writeSymbol = ' '; //we don't write anything to the tape
        q1_partialTransition[2].headDirection = RIGHT;
        q1_partialTransition[2].nextState = "q_reject";
    q1_functionTable.insert( pair<char, TransitionFunction>('0',q1_partialTransition[0]) );
    q1_functionTable.insert( pair<char, TransitionFunction>('x',q1_partialTransition[1]) );
    q1_functionTable.insert( pair<char, TransitionFunction>('#',q1_partialTransition[2]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q1", q1_functionTable) );


    //q2
    functionLookupTable q2_functionTable;
    vector<TransitionFunction> q2_partialTransition(3);
        //q2 on 0
        q2_partialTransition[0].writeSymbol = 'x';
        q2_partialTransition[0].headDirection = RIGHT;
        q2_partialTransition[0].nextState = "q3";
        
        //q2 on x
        q2_partialTransition[1].writeSymbol = ' '; //we don't write anything to the tape
        q2_partialTransition[1].headDirection = RIGHT;
        q2_partialTransition[1].nextState = "q2"; //we stay in the same state but advance to the next character

        //q2 on #
        q2_partialTransition[2].writeSymbol = ' ';
        q2_partialTransition[2].headDirection = RIGHT;
        q2_partialTransition[2].nextState = "q_accept";
    q2_functionTable.insert( pair<char, TransitionFunction>('0', q2_partialTransition[0]) );
    q2_functionTable.insert( pair<char, TransitionFunction>('x', q2_partialTransition[1]) );
    q2_functionTable.insert( pair<char, TransitionFunction>('#', q2_partialTransition[2]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q2", q2_functionTable) );


    //q3
    functionLookupTable q3_functionTable;
    vector<TransitionFunction> q3_partialTransition(3);
        //q3 on 0
        q3_partialTransition[0].writeSymbol = ' ';
        q3_partialTransition[0].headDirection = RIGHT;
        q3_partialTransition[0].nextState = "q4";

        //q3 on x
        q3_partialTransition[1].writeSymbol = ' ';
        q3_partialTransition[1].headDirection = RIGHT;
        q3_partialTransition[1].nextState = "q3";

        //q3 on #
        q3_partialTransition[2].writeSymbol =  ' ';
        q3_partialTransition[2].headDirection = LEFT;
        q3_partialTransition[2].nextState = "q5";
    q3_functionTable.insert( pair<char, TransitionFunction>('0', q3_partialTransition[0]) );
    q3_functionTable.insert( pair<char, TransitionFunction>('x', q3_partialTransition[1]) );
    q3_functionTable.insert( pair<char, TransitionFunction>('#', q3_partialTransition[2]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q3", q3_functionTable) );


    //q4
    functionLookupTable q4_functionTable;
    vector<TransitionFunction> q4_partialTransition(3);
        //q4 on 0
        q4_partialTransition[0].writeSymbol = 'x';
        q4_partialTransition[0].headDirection = RIGHT;
        q4_partialTransition[0].nextState = "q3";
        
        //q4 on x
        q4_partialTransition[1].writeSymbol = ' ';
        q4_partialTransition[1].headDirection = RIGHT;
        q4_partialTransition[1].nextState = "q4";

        //q4 on #
        q4_partialTransition[2].writeSymbol =  ' ';
        q4_partialTransition[2].headDirection = RIGHT;
        q4_partialTransition[2].nextState = "q_reject";
    q4_functionTable.insert( pair<char, TransitionFunction>('0', q4_partialTransition[0]) );
    q4_functionTable.insert( pair<char, TransitionFunction>('x', q4_partialTransition[1]) );
    q4_functionTable.insert( pair<char, TransitionFunction>('#', q4_partialTransition[2]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q4", q4_functionTable) );


    //q5
    functionLookupTable q5_functionTable;
    vector<TransitionFunction> q5_partialTransition(3);
        //q5 on 0
        q5_partialTransition[0].writeSymbol = ' ';
        q5_partialTransition[0].headDirection = LEFT;
        q5_partialTransition[0].nextState = "q5";

        //q5 on x
        q5_partialTransition[1].writeSymbol = ' ';
        q5_partialTransition[1].headDirection = LEFT;
        q5_partialTransition[1].nextState = "q5";

        //q5 on #
        q5_partialTransition[2].writeSymbol = ' ';
        q5_partialTransition[2].headDirection = RIGHT;
        q5_partialTransition[2].nextState = "q2";
    q5_functionTable.insert( pair<char, TransitionFunction>('0', q5_partialTransition[0]) );
    q5_functionTable.insert( pair<char, TransitionFunction>('x', q5_partialTransition[1]) );
    q5_functionTable.insert( pair<char, TransitionFunction>('#', q5_partialTransition[2]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q5", q5_functionTable) );


    //q_accept
    functionLookupTable q_accept_functionTable;
    vector<TransitionFunction> q_accept_partialTransition(1);
        //q_accept has no transitions
        q_accept_partialTransition[0].writeSymbol = ' ';
        q_accept_partialTransition[0].headDirection = STAY;
        q_accept_partialTransition[0].nextState = "q_accept";
    q_accept_functionTable.insert( pair<char, TransitionFunction>(' ', q_accept_partialTransition[0]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q_accept", q_accept_functionTable) );

    
    //q_reject
    functionLookupTable q_reject_functionTable;
    vector<TransitionFunction> q_reject_partialTransition(1);
        //q_reject has no transitions
        q_reject_partialTransition[0].writeSymbol = ' ';
        q_reject_partialTransition[0].headDirection = STAY;
        q_reject_partialTransition[0].nextState = "q_reject";
    q_reject_functionTable.insert( pair<char, TransitionFunction>(' ', q_reject_partialTransition[0]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q_reject", q_reject_functionTable) );
}

/**
 * The set of states.  This vector must be initialized in such a way that the
 * first element in the vector is the initial start state.
 *
 *
 */
vector<string> ExampleConfig::getSetOfStates() {
    vector<string> setOfStates(7);
  
    setOfStates[0] = "q1";
    setOfStates[1] = "q2";
    setOfStates[2] = "q3";
    setOfStates[3] = "q4";
    setOfStates[4] = "q5";
    setOfStates[5] = "q_accept";
    setOfStates[6] = "q_reject";

    return setOfStates;
}


vector<string> ExampleConfig::getInputAlphabet() {
    vector<string> inputAlphabet(1);

    inputAlphabet[0] = "0";        

    return inputAlphabet; 
}


vector<string> ExampleConfig::getTapeAlphabet() {
    vector<string> tapeAlphabet(3);
    
    tapeAlphabet[0] = "0";
    tapeAlphabet[1] = "x";
    tapeAlphabet[2] = "#";

    return tapeAlphabet;
}

TransitionFunction ExampleConfig::getTransitionFunction(string state, char tapeCharacter) {

    return (transitionLookupTable["state"])[tapeCharacter];
}
