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

list clist clist2 dlist pqueue queue stack recurse-factor recurse-facttail:
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

examples/recurse/ex-1.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
examples/recurse/ex-1.o: /usr/include/sys/_symbol_aliasing.h
examples/recurse/ex-1.o: /usr/include/sys/_posix_availability.h
examples/recurse/ex-1.o: /usr/include/Availability.h
examples/recurse/ex-1.o: /usr/include/AvailabilityInternal.h
examples/recurse/ex-1.o: /usr/include/_types.h /usr/include/sys/_types.h
examples/recurse/ex-1.o: /usr/include/machine/_types.h
examples/recurse/ex-1.o: /usr/include/i386/_types.h
examples/recurse/ex-1.o: /usr/include/sys/_pthread/_pthread_types.h
examples/recurse/ex-1.o: /usr/include/sys/_types/_va_list.h
examples/recurse/ex-1.o: /usr/include/sys/_types/_size_t.h
examples/recurse/ex-1.o: /usr/include/sys/_types/_null.h
examples/recurse/ex-1.o: /usr/include/sys/stdio.h
examples/recurse/ex-1.o: /usr/include/sys/_types/_off_t.h
examples/recurse/ex-1.o: /usr/include/sys/_types/_ssize_t.h
examples/recurse/ex-1.o: /usr/include/secure/_stdio.h
examples/recurse/ex-1.o: /usr/include/secure/_common.h include/fact.h
examples/recurse/ex-1.o: include/facttail.h
source/fact.o: include/fact.h
source/facttail.o: include/facttail.h
source/utils.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
source/utils.o: /usr/include/sys/_symbol_aliasing.h
source/utils.o: /usr/include/sys/_posix_availability.h
source/utils.o: /usr/include/Availability.h
source/utils.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
source/utils.o: /usr/include/sys/_types.h /usr/include/machine/_types.h
source/utils.o: /usr/include/i386/_types.h
source/utils.o: /usr/include/sys/_pthread/_pthread_types.h
source/utils.o: /usr/include/sys/_types/_va_list.h
source/utils.o: /usr/include/sys/_types/_size_t.h
source/utils.o: /usr/include/sys/_types/_null.h /usr/include/sys/stdio.h
source/utils.o: /usr/include/sys/_types/_off_t.h
source/utils.o: /usr/include/sys/_types/_ssize_t.h
source/utils.o: /usr/include/secure/_stdio.h /usr/include/secure/_common.h
source/utils.o: include/utils.h /usr/include/stdlib.h /usr/include/sys/wait.h
source/utils.o: /usr/include/sys/_types/_pid_t.h
source/utils.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
source/utils.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
source/utils.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
source/utils.o: /usr/include/i386/_mcontext.h
source/utils.o: /usr/include/mach/i386/_structs.h
source/utils.o: /usr/include/sys/_pthread/_pthread_attr_t.h
source/utils.o: /usr/include/sys/_types/_sigaltstack.h
source/utils.o: /usr/include/sys/_types/_ucontext.h
source/utils.o: /usr/include/sys/_types/_sigset_t.h
source/utils.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
source/utils.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
source/utils.o: /usr/include/sys/_types/_int16_t.h
source/utils.o: /usr/include/sys/_types/_int32_t.h
source/utils.o: /usr/include/sys/_types/_int64_t.h
source/utils.o: /usr/include/_types/_uint8_t.h
source/utils.o: /usr/include/_types/_uint16_t.h
source/utils.o: /usr/include/_types/_uint32_t.h
source/utils.o: /usr/include/_types/_uint64_t.h
source/utils.o: /usr/include/sys/_types/_intptr_t.h
source/utils.o: /usr/include/sys/_types/_uintptr_t.h
source/utils.o: /usr/include/_types/_intmax_t.h
source/utils.o: /usr/include/_types/_uintmax_t.h
source/utils.o: /usr/include/sys/_types/_timeval.h
source/utils.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
source/utils.o: /usr/include/sys/_endian.h
source/utils.o: /usr/include/libkern/_OSByteOrder.h
source/utils.o: /usr/include/libkern/i386/_OSByteOrder.h
source/utils.o: /usr/include/alloca.h /usr/include/sys/_types/_ct_rune_t.h
source/utils.o: /usr/include/sys/_types/_rune_t.h
source/utils.o: /usr/include/sys/_types/_wchar_t.h
source/utils.o: /usr/include/machine/types.h /usr/include/i386/types.h
source/utils.o: /usr/include/sys/_types/_dev_t.h
source/utils.o: /usr/include/sys/_types/_mode_t.h
