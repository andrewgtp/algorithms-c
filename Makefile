# Define the directories in which to search for library files
LIBDRS =

# Define the directories in which to search for include files
INCDRS = -I$(ALGOWC_TOPDIR)/include

# Define the library files
LIBFLS = 

# Define the source files
SRCFLS = $(ALGOWC_TOPDIR)/examples/list/ex-1.c\
	$(ALGOWC_TOPDIR)/source/list.c \
	$(ALGOWC_TOPDIR)/source/utils.c
         
# Define the object files 
OBJFLS = $(ALGOWC_TOPDIR)/examples/list/ex-1.o\
         $(ALGOWC_TOPDIR)/source/list.o \
         $(ALGOWC_TOPDIR)/source/utils.o

# Define the executable
EXE    = ex-1

# Define the compile and link options
CC     = c89
LL     = c89
CFLAGS =
LFLAGS =

# Define the rules
$(EXE): $(OBJFLS)
	$(LL) $(LFLAGS) -o $@ $(OBJFLS) $(LIBDRS) $(LIBFLS)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $(INCDRS) $<

all:
	make clean
	make depend

depend:
	make depend $(INCDRS) $(SRCFLS)
	make $(EXE)

clean:
	-rm -rf $(EXE)
	-rm -rf $(OBJFLS)
	-rm -rf $(ALGOWC_TOPDIR)/source/$(OBJFLS)

# DO NOT DELETE THIS LINE -- make depend depends on it
