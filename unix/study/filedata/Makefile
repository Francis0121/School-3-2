# File Name
NAME = filedata
MAIN = main

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
CFILES = $(SRCDIR)$(MAIN).c \
	$(SRCDIR)$(NAME).c 

OBJS = $(OBJDIR)$(MAIN).o \
	$(OBJDIR)$(NAME).o

# Compile
CC = gcc
CFLAGS = -g -Wall

all: $(NAME).exe

tag: $(HDRS) $(CFILES)
	ctags $(HDRS) $(CFILES)

$(NAME).exe: $(OBJS)
	$(CC) -o $(NAME).exe $(OBJS)

$(OBJDIR)$(MAIN).o: $(SRCDIR)$(MAIN).c
	$(CC) $(CFLAGS) -c $(SRCDIR)$(MAIN).c -o $(OBJDIR)$(MAIN).o
$(OBJDIR)$(NAME).o: $(SRCDIR)$(NAME).c
	$(CC) $(CFLAGS) -c $(SRCDIR)$(NAME).c -o $(OBJDIR)$(NAME).o
