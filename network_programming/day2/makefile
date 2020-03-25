#get all .c files
SrcFiles=$(wildcard *.c)
EXF=$(SrcFiles:%.c=%)
.PHONY:clean all
all:$(EXF)

$(EXF):%:%.c
		gcc $^ -o $@ 

clean:
		rm *.o

