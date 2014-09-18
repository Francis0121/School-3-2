CURDIR  = ./

SRCDIR  = ./
OBJDIR  = ./obj/

SUFFIXES = .o .c .h
.SUFFIXES: $(SUFFIXES)

PROJ = test

CFILES = $(SRCDIR)a.c \
	$(SRCDIR)b.c \
	$(SRCDIR)c.c

OBJS = $(OBJDIR)a.o \
	$(OBJDIR)b.o\
	$(OBJDIR)c.o

CC= gcc
CFLAGS= -g -Wall

all: test.exe

tag: $(HDRS) $(CFILES)
	ctags $(HDRS) $(CFILES)
test.exe: $(OBJS)
	$(CC) -o test.exe $(OBJS)

$(OBJDIR)a.o: $(SRCDIR)a.c
	$(CC) $(CFLAGS) -c $(SRCDIR)a.c -o $(OBJDIR)a.o
$(OBJDIR)b.o: $(SRCDIR)b.c
	$(CC) $(CFLAGS) -c $(SRCDIR)b.c -o $(OBJDIR)b.o
$(OBJDIR)c.o: $(SRCDIR)c.c
	$(CC) $(CFLAGS) -c $(SRCDIR)c.c -o $(OBJDIR)c.o
