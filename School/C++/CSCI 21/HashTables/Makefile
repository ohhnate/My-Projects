CPP_FLAGS = -std=c++11 -Wall -Wextra -Werror

# uncomment for Linux/Mac OS X
#RM = rm -f

# uncomment for Windows (make sure MinGW/MSYS are installed!)
#RM = del

unittest.exe: unittest.cpp hash_table.o
	g++ $(CPP_FLAGS) unittest.cpp hash_table.o -o unittest.exe

hash_table.o: hash_table.h hash_table.cpp
	g++ $(CPP_FLAGS) -c hash_table.cpp -o hash_table.o

clean:
	$(RM) *.o

cleanall: clean
	$(RM) *.exe
