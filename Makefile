# temp storage of target
TARGET=$(shell cat TARGET)

# define the directories in which to search for library files
PATH_LIBS =

# define the directories in which to search for include files
PATH_INCLUDE = -I include
PATH_SRC = source
PATH_EX = examples

# define the library files
FILES_LIBS = 

# define the source & object files (most cases)
FILES_SRC = $(PATH_EX)/$(TARGET)/ex-1.c\
	$(PATH_SRC)/$(TARGET).c \
	$(PATH_SRC)/utils.c
         
FILES_OBJ = $(PATH_EX)/$(TARGET)/ex-1.o\
         $(PATH_SRC)/$(TARGET).o \
         $(PATH_SRC)/utils.o

# partial Makefiles will override for special cases
ifeq ($(TARGET),clist2)
    include examples/clist/Makefile.$(TARGET)
else ifeq ($(TARGET), $(filter $(TARGET),stack queue pqueue))
    include examples/$(TARGET)/Makefile.$(TARGET)
else ifeq ($(TARGET),recurse-facttail)
    include examples/recurse/Makefile.facttail
else ifeq ($(TARGET),recurse-factor)
    include examples/recurse/Makefile.factor
else ifeq ($(TARGET),search)
    include examples/$(TARGET)/Makefile.$(TARGET)
else ifeq ($(TARGET),spell)
    include examples/search/Makefile.$(TARGET)
else ifeq ($(TARGET),set)
    include examples/$(TARGET)/Makefile.$(TARGET)
else ifeq ($(TARGET),set-cover)
    include examples/set/Makefile.cover
endif

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

list clist clist2 dlist pqueue queue stack recurse-factor recurse-facttail search spell set set-cover:
	make clean
	@echo "$@" > TARGET 
	make depend

depend:
	makedepend $(PATH_INCLUDE) $(FILES_SRC)
	make $(EXE)

.PHONY: 
clean:
	-rm -rf $(EXE) $(FILES_OBJ)

run:
	./$(EXE)


# DO NOT DELETE THIS LINE -- make depend depends on it
