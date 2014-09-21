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
CFILES = $(SRCDIR)read.c

OBJS = $(OBJDIR)read.o

# Compile
CC = gcc
CFLAGS = -g -Wall

all: read.exe

tag: $(HDRS) $(CFILES)
	ctags $(HDRS) $(CFILES)

read.exe: $(OBJS)
	$(CC) -o read.exe $(OBJS)

$(OBJDIR)read.o: $(SRCDIR)read.c
	$(CC) $(CFLAGS) -c $(SRCDIR)read.c -o $(OBJDIR)read.o
