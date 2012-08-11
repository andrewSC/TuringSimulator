#include "ExampleConfig.h"

typedef map<char, TransitionFunction> functionLookupTable;
map<string, functionLookupTable> transitionLookupTable;

ExampleConfig::ExampleConfig() {
    setSetOfStates(); //init our set of states    
    //q1
    functionLookupTable q1_functionTable;
    vector<TransitionFunction> q1_partialTransition(1);
        //q1 on empty character
        q1_partialTransition[0].writeSymbol = '\a'; //we don't write anything to the tape
        q1_partialTransition[0].headDirection = RIGHT;
        q1_partialTransition[0].nextState = "q2";
    q1_functionTable.insert( pair<char, TransitionFunction>('\a',q1_partialTransition[0]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q1", q1_functionTable) );


    //q2
    functionLookupTable q2_functionTable;
    vector<TransitionFunction> q2_partialTransition(3);
        //q2 on 0
        q2_partialTransition[0].writeSymbol = '\a';
        q2_partialTransition[0].headDirection = RIGHT;
        q2_partialTransition[0].nextState = "q2";
        
        //q2 on 1
        q2_partialTransition[1].writeSymbol = '\a'; //we don't write anything to the tape
        q2_partialTransition[1].headDirection = RIGHT;
        q2_partialTransition[1].nextState = "q2"; //we stay in the same state but advance to the next character

        //q2 on #
        q2_partialTransition[2].writeSymbol = '\a';
        q2_partialTransition[2].headDirection = RIGHT;
        q2_partialTransition[2].nextState = "q3";
    q2_functionTable.insert( pair<char, TransitionFunction>('0', q2_partialTransition[0]) );
    q2_functionTable.insert( pair<char, TransitionFunction>('1', q2_partialTransition[1]) );
    q2_functionTable.insert( pair<char, TransitionFunction>('#', q2_partialTransition[2]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q2", q2_functionTable) );


    //q3
    functionLookupTable q3_functionTable;
    vector<TransitionFunction> q3_partialTransition(3);
        //q3 on 0
        q3_partialTransition[0].writeSymbol = '\a';
        q3_partialTransition[0].headDirection = RIGHT;
        q3_partialTransition[0].nextState = "q3";

        //q3 on 1
        q3_partialTransition[1].writeSymbol = '\a';
        q3_partialTransition[1].headDirection = RIGHT;
        q3_partialTransition[1].nextState = "q3";

        //q3 on empty character
        q3_partialTransition[2].writeSymbol = '\a';
        q3_partialTransition[2].headDirection = RIGHT;
        q3_partialTransition[2].nextState = "q_accept";
    q3_functionTable.insert( pair<char, TransitionFunction>('0', q3_partialTransition[0]) );
    q3_functionTable.insert( pair<char, TransitionFunction>('1', q3_partialTransition[1]) );
    q3_functionTable.insert( pair<char, TransitionFunction>('\a', q3_partialTransition[2]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q3", q3_functionTable) );


    //q_accept
    functionLookupTable q_accept_functionTable;
    vector<TransitionFunction> q_accept_partialTransition(1);
        //q_accept has no transitions
        q_accept_partialTransition[0].writeSymbol = '\a';
        q_accept_partialTransition[0].headDirection = STAY;
        q_accept_partialTransition[0].nextState = "q_accept";
    q_accept_functionTable.insert( pair<char, TransitionFunction>('\a', q_accept_partialTransition[0]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q_accept", q_accept_functionTable) );

    
    //q_reject
    functionLookupTable q_reject_functionTable;
    vector<TransitionFunction> q_reject_partialTransition(1);
        //q_reject has no transitions
        q_reject_partialTransition[0].writeSymbol = '\a';
        q_reject_partialTransition[0].headDirection = STAY;
        q_reject_partialTransition[0].nextState = "q_reject";
    q_reject_functionTable.insert( pair<char, TransitionFunction>('\a', q_reject_partialTransition[0]) );
    transitionLookupTable.insert( pair<string, functionLookupTable>("q_reject", q_reject_functionTable) );
}

/**
 * The set of states.  This vector must be initialized in such a way that the
 * first element in the vector is the initial start state and the last two elements
 * are the accept and reject states in that order.
 *
 *
 */
void ExampleConfig::setSetOfStates() {
    setOfStates.push_back("q1");
    setOfStates.push_back("q2");
    setOfStates.push_back("q3");
    setOfStates.push_back("q_accept");
    setOfStates.push_back("q_reject");
}

vector<string> ExampleConfig::getSetOfStates() {
    return setOfStates;
}

string ExampleConfig::getAcceptState() {
    return setOfStates[(setOfStates.size()-2)];
}

string ExampleConfig::getRejectState() {
    return setOfStates[(setOfStates.size()-1)];
}


vector<string> ExampleConfig::getInputAlphabet() {
    vector<string> inputAlphabet(3);

    inputAlphabet[0] = "0";
    inputAlphabet[1] = "1";
    inputAlphabet[2] = "#"; 

    return inputAlphabet; 
}


vector<char> ExampleConfig::getTapeAlphabet() {
    vector<char> tapeAlphabet(3);
    
    tapeAlphabet[0] = '0';
    tapeAlphabet[1] = '1';
    tapeAlphabet[2] = '\a';//how this program defines the empty spaces on a tape

    return tapeAlphabet;
}

TransitionFunction* ExampleConfig::getTransitionFunction(string state, char tapeCharacter) {
    TransitionFunction* partialTransition = NULL;
    map<string, functionLookupTable>::iterator transitionLookupIterator;


    transitionLookupIterator = transitionLookupTable.find(state);
    if (transitionLookupIterator != transitionLookupTable.end()) {

        map<char, TransitionFunction>::iterator partialTransitionIterator; 
        partialTransitionIterator = (transitionLookupIterator->second).find(tapeCharacter);

        if (partialTransitionIterator != (transitionLookupIterator->second).end()) {
            partialTransition = &(partialTransitionIterator->second);
        }
    }
 
    return partialTransition;
}
