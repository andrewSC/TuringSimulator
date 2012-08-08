COMPILER = clang++

TuringSimulator:
	${COMPILER} -v  TuringSimulator.cpp -o TuringSimulator
clean:
	rm -f TuringSimulator *.out *.o .*.swp .*.swo
