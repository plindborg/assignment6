# Makefile template for shared library
 
CC = gcc # C compiler
CFLAGS = -fPIC -Wall -Wextra -O2 -g -std=c99 # C flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
TARGET_LIB = libresistance.so # target lib
 
SRCS = main.c resistance.c # source files
OBJS = $(SRCS:.c=.o)
 
all: ${TARGET_LIB}
 
$(TARGET_LIB): $(OBJS)
	$(CC) ${LDFLAGS} -o $@ $^
 
$(SRCS:.c=.d):%.d:%.c
	$(CC) $(CFLAGS) -MM $< >$@
 
include $(SRCS:.c=.d)
 
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.c=.d)
