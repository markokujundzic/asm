./bin/assembler : $(patsubst ./src/%.cpp, ./bin/%.o, $(wildcard ./src/*.cpp))
	g++ -static -I ./src -std=c++17 $^ -o $@ 

./bin/%.o : ./src/%.cpp
	g++ -static -I ./src -std=c++17 -c $< -o $@ 

clean:
	rm -f ./bin/*.o
	rm -f .bin/assembler

.PHONY: clean

run: 
	./run.sh
