CXX = g++
CXXFLAG = -ggdb -Wall

C_FILES = $(wildcard src/*.cc)
OBJS = $(addprefix obj/,$(notdir $(C_FILES:.cc=.o)))

all: $(OBJS)
	$(CXX) $(CXXFLAGS) obj/*.o -o solver

obj/%.o: src/%.cc
	$(CXX) $(CXXFLAGS) $< -c -o $@

clean:
	rm -rf ./obj/*
	rm -rf ./solver.exe

-include $(OBJS:.o=.d)

