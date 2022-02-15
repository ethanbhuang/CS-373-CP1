all: huang_p1

huang_p1: main.o State.o TuringMachine.o
	g++ main.o State.o TuringMachine.o -o huang_p1

main.o: main.cpp
	g++ -c main.cpp -o $@

State.o: State.cpp State.h Transition.h
	g++ -c State.cpp -o $@

TuringMachine.p: TuringMachine.cpp TuringMachine.h
	g++ -c TuringMachine.cpp -o $@

clean:
	rm -f *.o huang_p1