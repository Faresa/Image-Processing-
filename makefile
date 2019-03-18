.SUFFIXES:
.SUFFIXES: .cpp .o

SOURCES=src/main.cpp src/Image.cpp
OBJECTS=$(SOURCES:.cpp=.o)
TEST_SOURCES=src/Image.cpp src/tests.cpp
TEST_OBJECTS=$(TEST_SOURCES:.cpp=.o)


default: $(OBJECTS)
	g++ $(SOURCES) -o bin/imageops -std=c++11

.cpp.o:
	g++ -c $< -o $@ -std=c++11

clean:
	rm -f $(OBJECTS) bin/imageops bin/test

run: default
	cd ./bin && ./imageops $(ARGS)

tests: $(OBJECTS)
	g++ $(TEST_SOURCES) -o bin/test -std=c++11

run-tests: tests
	cd ./bin && ./test
