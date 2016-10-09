CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =	test_geo/geoobj.o test_geo/point.o test_geo/line.o test_geo/rectangle.o test_geo/geogroup.o test_cpp.o

LIBS =

TARGET =	test_cpp.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
