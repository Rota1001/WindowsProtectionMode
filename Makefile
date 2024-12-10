CXX = g++

CXXFLAGS = -I./include

TARGET = bin\protection.dll

SRCS = $(wildcard src/*.cpp)

OBJS = $(SRCS:src/%.cpp=build/%.o)

all: build bin $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -shared -o $(TARGET) $(OBJS)

build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f build/*.o
	rm -f bin/*.dll

bin:
	if [ ! -d bin ]; then mkdir bin; fi

build:
	if [ ! -d build ]; then mkdir build; fi
