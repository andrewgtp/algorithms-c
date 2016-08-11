# temp storage of target
TARGET = $(shell cat TARGET)

# define the directories in which to search for library files
PATH_LIBS =

# define the directories in which to search for include files
PATH_INCLUDE = -I include
PATH_SRC = source
PATH_EX = examples

# define the library files
FILES_LIBS = 

# define the source files
FILES_SRC = $(PATH_EX)/$(TARGET)/ex-1.c\
	$(PATH_SRC)/$(TARGET).c \
	$(PATH_SRC)/utils.c
         
FILES_SRC_2 = $(PATH_EX)/$(TARGET)/ex-2.c\
	$(PATH_SRC)/$(TARGET).c \
	$(PATH_SRC)/page.c \
	$(PATH_SRC)/utils.c

# define the object files 
FILES_OBJ = $(PATH_EX)/$(TARGET)/ex-1.o\
         $(PATH_SRC)/$(TARGET).o \
         $(PATH_SRC)/utils.o

FILES_OBJ_2 = $(PATH_EX)/$(TARGET)/ex-2.o\
         $(PATH_SRC)/$(TARGET).o \
         $(PATH_SRC)/page.o \
         $(PATH_SRC)/utils.o


# define the executable
EXE    = ex.out 

# define the compile and link options
CC     = c89
LL     = c89
CFLAGS =
LFLAGS =


# define the rules
$(EXE): $(FILES_OBJ)
	$(LL) $(LFLAGS) -o $@ $(FILES_OBJ) $(PATH_LIBS) $(FILES_LIBS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $(PATH_INCLUDE) $<

list clist dlist:
	make clean
	@echo "$@" > TARGET 
	make depend

depend:
	makedepend $(PATH_INCLUDE) $(FILES_SRC)
	make $(EXE)

clean:
	-rm -rf $(EXE) $(FILES_OBJ) TARGET

run:
	./$(EXE)


# DO NOT DELETE THIS LINE -- make depend depends on it
