# File Name
NAME = pwd

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
CFILES = $(SRCDIR)$(NAME).c

OBJS = $(OBJDIR)$(NAME).o

# Compile
CC = gcc
CFLAGS = -g -Wall

all: $(NAME).exe

tag: $(HDRS) $(CFILES)
	ctags $(HDRS) $(CFILES)

$(NAME).exe: $(OBJS)
	$(CC) -o $(NAME).exe $(OBJS)

$(OBJDIR)$(NAME).o: $(SRCDIR)$(NAME).c
	$(CC) $(CFLAGS) -c $(SRCDIR)$(NAME).c -o $(OBJDIR)$(NAME).o
