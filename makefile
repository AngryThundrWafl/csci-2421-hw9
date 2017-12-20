.SUFFIXES : .cc
.SUFFIXES : .c
.SUFFIXES : .cpp

INCDIR =
LIBDIR =

CC = g++

CXXFLAGS = -g

LIBS = -lm

OBJS = main.o HashTable.o LinkedList.o

TARGET = Homework9

$(TARGET): $(OBJS)
	$(CC) -std=c++11 -o $@ $(OBJS) $(LIBDIR) $(LIBS)

.cc.o:
	$(CC)-std=c++11 -c $(CXXFLAGS) $(INCDIR) $<

.c.o:
	$(CC)-std=c++11 -c $(CXXFLAGS) $(INCDIR) $<

.cpp.o:
	$(CC)-std=c++11 -c $(CXXFLAGS) $(INCDIR) $<

clean:
	rm -f $(OBJS) $(TARGET) core



