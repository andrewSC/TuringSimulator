COMPILER = clang++

TuringSimulator: TuringSimulator.o Tape.o State.o Head.o ExampleConfig.o
	${COMPILER} -v -o TuringSimulator TuringSimulator.o Tape.o State.o Head.o ExampleConfig.o

TuringSimulator.o: TuringSimulator.cpp Tape.o Direction.h
	${COMPILER} -c TuringSimulator.cpp

Tape.o: Tape.cpp Tape.h
	${COMPILER} -c Tape.cpp

State.o: State.cpp State.h
	${COMPILER} -c State.cpp

Head.o: Head.cpp Head.h
	${COMPILER} -c Head.cpp

ExampleConfig.o: ExampleConfig.cpp ExampleConfig.h
	${COMPILER} -c ExampleConfig.cpp

clean:
	rm -f TuringSimulator *.out *.o .*.swp .*.swo
