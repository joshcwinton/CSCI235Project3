main: main.o
	g++ -o main main.cpp -std=gnu++0x; ./main

main.o: main.cpp
	g++ -c main.cpp -std=gnu++0x

format:
	clang-format -i *.cpp *.h

clean:
	rm -rf main
