all: myprogram

myprogram: Lab3.o LinkedList.o Node.o
	g++ -o myprogram LinkedList.o Node.o Lab3.o

Lab3.o: Lab3.cpp
	g++ -c Lab3.cpp

LinkedList.o: LinkedList.cpp
	g++ -c LinkedList.cpp

Node.o: Node.cpp
	g++ -c Node.cpp

clean:
	rm *.o myprogram
