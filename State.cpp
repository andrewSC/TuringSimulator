#include "State.h"

State::State() { //if the default constructor is used just initialize to empty.
    setWriteSymbol("");
    setHeadDirection(0); //the 'stay put' direction

}

State::State(string symbolToWrite, int direction) {
    setWriteSymbol(symbolToWrite);
    setHeadDirection(direction);
}


void State::setNextState(State& nextStateTransition) {
    *nextState = nextStateTransition;
}

State& State::getNextState() {
    return *nextState;
}


void State::setWriteSymbol(string symbolToWrite) {
    writeSymbol = symbolToWrite;
}


string State::getWriteSymbol() {
    return writeSymbol;
}


void State::setHeadDirection(int direction) {
    headDirection = direction;
}
