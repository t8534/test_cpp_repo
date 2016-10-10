# headers subdirs
#IDIRS = -I. -I"C:/MinGW/include" -I"C:/MinGW/include/lib/gcc/mingw32/4.5.0/include" -I"C:/MinGW/include/lib/gcc/mingw32/4.5.0/include-fixed" -I./libs/sdl/include -I./libs/sdl/include/SDL
IDIRS = -I./lib/include/SDL2 

#CC=gcc   
#CFLAGS=-c -v -Wall $(IDIRS) 

CXX=g++
CXXFLAGS=-c -Wall $(IDIRS) 

LDFLAGS= 
LDLIBS= -L./lib/libs -lmingw32 -lSDL2main -lSDL2


%.o: %.c
	$(CC) $(CFLAGS) $<


#%.o: %.cpp
#	$(CC) $(CFLAGS) $<


# all source subdirs for linker and compilator
#VPATH = ./ libs libs/sdl libs/sdl/libs

all : t3_sdl2.exe

# At linker below library paths and libraries must be at the end of line.
t3_sdl2.exe : t3_sdl2.o   
	$(CC) -o t3_sdl2.exe t3_sdl2.o $(LDLIBS)


clean:
	rm -f t3_sdl2.exe t3_sdl2.o



