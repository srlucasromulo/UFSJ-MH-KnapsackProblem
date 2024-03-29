# ### A simple basic-purpose makefile ###
# 1) Change the exec name.

# Executable
EXEC = knapsack_problem

# Binary
BIN = ./bin/$(EXEC)

# Source files
SRC = $(wildcard ./src/*.c)

# Objects
OBJ = $(subst src,obj,$(subst .c,.o,$(SRC)))

# Compiler
CC = cc

# Compiler flags
CFLAGS = -lm -Wall
CCFLAGS = $(CFLAGS)


# Compiling and linking
#
.PHONY: all objFolder binFolder
all: objFolder binFolder $(BIN)

$(BIN): $(OBJ)
	@ echo 'Building binary $@ using $(CC)...'
	@ $(CC) $(OBJ) -o $@ $(CCFLAGS)
	@ echo 'Finished building $@.'

./obj/%.o: ./src/%.c ./src/*.h
	@ echo 'Building $@ from $<...'
	@ $(CC)  -c $< -o $@ $(CCFLAGS)
	@ echo 'ok'

objFolder:
	@ if [ ! -d ./obj ]; then \
		echo 'Creating objects folder...' ; \
		mkdir -p obj ; \
		echo 'ok'; \
	fi

binFolder:
	@ if [ ! -d ./bin ]; then \
		echo 'Creating binary folder...' ; \
		mkdir -p bin ; \
		echo 'ok'; \
	fi

.PHONY: clean
clean:
	@ echo 'Cleanning up...'
	@ rm -rf ./obj/* ./obj
	@ rm -rf ./bin/* ./bin
	@ echo 'ok'
