# File Name
MAIN = nfa

# Current Directory
CURDIR = ./

# Source Directory
SRCDIR = ./

# Object Directory
OBJDIR = ./

# Suffix file name
SUFFIXES = .o .c .h
.SUFFIXES: $(SUFFIXES)

# Project Name
PROJ = file

# Compile File
CFILES = $(SRCDIR)$(MAIN).c

OBJS = $(OBJDIR)$(MAIN).o

# Compile
CC = gcc
CFLAGS = -g -Wall

all: $(MAIN).exe

tag: $(HDRS) $(CFILES)
	ctags $(HDRS) $(CFILES)

$(MAIN).exe: $(OBJS)
	$(CC) -o $(MAIN).exe $(OBJS)

$(OBJDIR)$(MAIN).o: $(SRCDIR)$(MAIN).c
	$(CC) $(CFLAGS) -c $(SRCDIR)$(MAIN).c -o $(OBJDIR)$(MAIN).o
