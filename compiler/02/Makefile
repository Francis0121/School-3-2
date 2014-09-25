# Current Directory
CURDIR = ./

# Source Directory
SRCDIR = ./

# Object Directory
OBJDIR = ./obj/

# Suffix file name
SUFFIXES = .o .c .h
.SUFFIXES: $(SUFFIXES)

# Project Name
PROJ = file

# Compile File
CFILES = $(SRCDIR)lgs.c

OBJS = $(OBJDIR)lgs.o

# Compile
CC = gcc
CFLAGS = -g -Wall

all: lgs.exe

tag: $(HDRS) $(CFILES)
	ctags $(HDRS) $(CFILES)

lgs.exe: $(OBJS)
	$(CC) -o lgs.exe $(OBJS)

$(OBJDIR)lgs.o: $(SRCDIR)lgs.c
	$(CC) $(CFLAGS) -c $(SRCDIR)lgs.c -o $(OBJDIR)lgs.o
