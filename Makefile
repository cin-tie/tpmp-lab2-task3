# Makefile for Marshrut project

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude
TARGET = bin/marshrut_program


OBJDIR = obj
OBJS = $(OBJDIR)/main.o $(OBJDIR)/marshrut.o

all: $(TARGET)

$(TARGET): $(OBJS) | bin
	$(CC) -o $(TARGET) $(OBJS)

$(OBJDIR)/main.o: src/main.c include/marshrut.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/main.c -o $(OBJDIR)/main.o

$(OBJDIR)/marshrut.o: src/marshrut.c include/marshrut.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c src/marshrut.c -o $(OBJDIR)/marshrut.o

bin:
	mkdir -p bin

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR) $(TARGET) bin

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
