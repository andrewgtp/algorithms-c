# Define the directories in which to search for library files
PATH_LIBS =

# Define the directories in which to search for include files
PATH_INCLUDE = -I$(PATH_ROOT)/include

# Define the library files
FILES_LIBS = 

# Define the source files
FILES_SRC = $(PATH_ROOT)/examples/list/ex-1.c\
	$(PATH_ROOT)/source/list.c \
	$(PATH_ROOT)/source/utils.c
         
# Define the object files 
FILES_OBJ = $(PATH_ROOT)/examples/list/ex-1.o\
         $(PATH_ROOT)/source/list.o \
         $(PATH_ROOT)/source/utils.o

# Define the executable
EXE    = ex.out 

# Define the compile and link options
CC     = c89
LL     = c89
CFLAGS =
LFLAGS =

# Define the rules
$(EXE): $(FILES_OBJ)
	$(LL) $(LFLAGS) -o $@ $(FILES_OBJ) $(PATH_LIBS) $(FILES_LIBS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $(PATH_INCLUDE) $<

list:
	echo "compile list code"	

dlist:
	echo "compile dlist code"	

clist:
	echo "compile clist code"	

stack:
	echo "compile stack code"	

queue:
	echo "compile queue code"	


all:
	make clean
	make depend

depend:
	make depend $(PATH_INCLUDE) $(FILES_SRC)
	make $(EXE)

clean:
	-rm -rf $(EXE)
	-rm -rf $(FILES_OBJ)
	-rm -rf $(PATH_ROOT)/source/$(FILES_OBJ)

# DO NOT DELETE THIS LINE -- make depend depends on it
