CC = g++
CFLAGS = -g
TARGET = driver
OBJS = log.o main.o
.SUFFIXES: .cpp .o

.DEFAULT_GOAL : $(TARGET)
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	/bin/rm -f *.o *.log $(TARGET)
