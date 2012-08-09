#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

#include "Tape.h"
#include "Machine.h"

using namespace std;

int main(int argc, char* argv[]) {

    if(argc != 2) { //needs one argument (the input string) to execute 

        printf("Usage: %s <input_string_to_test>\n", argv[0]);

    } else {

        Tape tmTape((string(argv[1])));
        Machine tMachine;
        tMachine.processTape(tmTape.getTape());

    }

    return 0;
}
