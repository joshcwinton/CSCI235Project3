main: main.o
	g++ -o main main.cpp; ./main

main.o: main.cpp
	g++ -c main.cpp

format:
	clang-format -i *.cpp *.h

clean:
	rm -rf main
