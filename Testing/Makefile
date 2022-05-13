CXXFLAGS := -std=c++14 -Wall -ggdb -O0 -fprofile-arcs -ftest-coverage

SOURCES := $(wildcard *.cpp)
OBJS := $(SOURCES:%.cpp=%.o)


TARGET := testMain 

.PHONY : all
all : $(TARGET)

$(TARGET) : $(OBJS)
	 $(CXX) $(CXXFLAGS) $^ -o $@ 

.PHONY : clean
clean : 
	rm -rf $(TARGET) $(OBJS) *.gcov *.gcda *.gcno Receipt* InventoryChangeLog.txt

.PHONY : run
run:
	./$(TARGET)

.PHONE : gcov
gcov:
	gcov -r *.cpp