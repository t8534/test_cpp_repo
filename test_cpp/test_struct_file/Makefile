CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		test_struct_file.o test_simple_struct_f.o test_structf.o

LIBS =

TARGET =	test_struct_file.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
