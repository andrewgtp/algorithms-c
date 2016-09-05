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
else ifeq ($(TARGET), $(filter $(TARGET),stack queue pqueue sort))
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
else ifeq ($(TARGET),directls)
    include examples/sort/Makefile.directls
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

list clist clist2 dlist pqueue queue stack recurse-factor recurse-facttail search spell set set-cover sort directls:
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

examples/list/ex-1.o: /usr/include/stdio.h /usr/include/sys/cdefs.h
examples/list/ex-1.o: /usr/include/sys/_symbol_aliasing.h
examples/list/ex-1.o: /usr/include/sys/_posix_availability.h
examples/list/ex-1.o: /usr/include/Availability.h
examples/list/ex-1.o: /usr/include/AvailabilityInternal.h
examples/list/ex-1.o: /usr/include/_types.h /usr/include/sys/_types.h
examples/list/ex-1.o: /usr/include/machine/_types.h
examples/list/ex-1.o: /usr/include/i386/_types.h
examples/list/ex-1.o: /usr/include/sys/_pthread/_pthread_types.h
examples/list/ex-1.o: /usr/include/sys/_types/_va_list.h
examples/list/ex-1.o: /usr/include/sys/_types/_size_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_null.h
examples/list/ex-1.o: /usr/include/sys/stdio.h
examples/list/ex-1.o: /usr/include/sys/_types/_off_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_ssize_t.h
examples/list/ex-1.o: /usr/include/secure/_stdio.h
examples/list/ex-1.o: /usr/include/secure/_common.h /usr/include/stdlib.h
examples/list/ex-1.o: /usr/include/sys/wait.h
examples/list/ex-1.o: /usr/include/sys/_types/_pid_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_id_t.h
examples/list/ex-1.o: /usr/include/sys/signal.h
examples/list/ex-1.o: /usr/include/sys/appleapiopts.h
examples/list/ex-1.o: /usr/include/machine/signal.h
examples/list/ex-1.o: /usr/include/i386/signal.h
examples/list/ex-1.o: /usr/include/machine/_mcontext.h
examples/list/ex-1.o: /usr/include/i386/_mcontext.h
examples/list/ex-1.o: /usr/include/mach/i386/_structs.h
examples/list/ex-1.o: /usr/include/sys/_pthread/_pthread_attr_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_sigaltstack.h
examples/list/ex-1.o: /usr/include/sys/_types/_ucontext.h
examples/list/ex-1.o: /usr/include/sys/_types/_sigset_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_uid_t.h
examples/list/ex-1.o: /usr/include/sys/resource.h /usr/include/stdint.h
examples/list/ex-1.o: /usr/include/sys/_types/_int8_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_int16_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_int32_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_int64_t.h
examples/list/ex-1.o: /usr/include/_types/_uint8_t.h
examples/list/ex-1.o: /usr/include/_types/_uint16_t.h
examples/list/ex-1.o: /usr/include/_types/_uint32_t.h
examples/list/ex-1.o: /usr/include/_types/_uint64_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_intptr_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_uintptr_t.h
examples/list/ex-1.o: /usr/include/_types/_intmax_t.h
examples/list/ex-1.o: /usr/include/_types/_uintmax_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_timeval.h
examples/list/ex-1.o: /usr/include/machine/endian.h
examples/list/ex-1.o: /usr/include/i386/endian.h /usr/include/sys/_endian.h
examples/list/ex-1.o: /usr/include/libkern/_OSByteOrder.h
examples/list/ex-1.o: /usr/include/libkern/i386/_OSByteOrder.h
examples/list/ex-1.o: /usr/include/alloca.h
examples/list/ex-1.o: /usr/include/sys/_types/_ct_rune_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_rune_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_wchar_t.h
examples/list/ex-1.o: /usr/include/machine/types.h /usr/include/i386/types.h
examples/list/ex-1.o: /usr/include/sys/_types/_dev_t.h
examples/list/ex-1.o: /usr/include/sys/_types/_mode_t.h include/list.h
examples/list/ex-1.o: include/utils.h
source/list.o: /usr/include/stdlib.h /usr/include/Availability.h
source/list.o: /usr/include/AvailabilityInternal.h /usr/include/_types.h
source/list.o: /usr/include/sys/_types.h /usr/include/sys/cdefs.h
source/list.o: /usr/include/sys/_symbol_aliasing.h
source/list.o: /usr/include/sys/_posix_availability.h
source/list.o: /usr/include/machine/_types.h /usr/include/i386/_types.h
source/list.o: /usr/include/sys/_pthread/_pthread_types.h
source/list.o: /usr/include/sys/wait.h /usr/include/sys/_types/_pid_t.h
source/list.o: /usr/include/sys/_types/_id_t.h /usr/include/sys/signal.h
source/list.o: /usr/include/sys/appleapiopts.h /usr/include/machine/signal.h
source/list.o: /usr/include/i386/signal.h /usr/include/machine/_mcontext.h
source/list.o: /usr/include/i386/_mcontext.h
source/list.o: /usr/include/mach/i386/_structs.h
source/list.o: /usr/include/sys/_pthread/_pthread_attr_t.h
source/list.o: /usr/include/sys/_types/_sigaltstack.h
source/list.o: /usr/include/sys/_types/_ucontext.h
source/list.o: /usr/include/sys/_types/_sigset_t.h
source/list.o: /usr/include/sys/_types/_size_t.h
source/list.o: /usr/include/sys/_types/_uid_t.h /usr/include/sys/resource.h
source/list.o: /usr/include/stdint.h /usr/include/sys/_types/_int8_t.h
source/list.o: /usr/include/sys/_types/_int16_t.h
source/list.o: /usr/include/sys/_types/_int32_t.h
source/list.o: /usr/include/sys/_types/_int64_t.h
source/list.o: /usr/include/_types/_uint8_t.h /usr/include/_types/_uint16_t.h
source/list.o: /usr/include/_types/_uint32_t.h
source/list.o: /usr/include/_types/_uint64_t.h
source/list.o: /usr/include/sys/_types/_intptr_t.h
source/list.o: /usr/include/sys/_types/_uintptr_t.h
source/list.o: /usr/include/_types/_intmax_t.h
source/list.o: /usr/include/_types/_uintmax_t.h
source/list.o: /usr/include/sys/_types/_timeval.h
source/list.o: /usr/include/machine/endian.h /usr/include/i386/endian.h
source/list.o: /usr/include/sys/_endian.h /usr/include/libkern/_OSByteOrder.h
source/list.o: /usr/include/libkern/i386/_OSByteOrder.h /usr/include/alloca.h
source/list.o: /usr/include/sys/_types/_ct_rune_t.h
source/list.o: /usr/include/sys/_types/_rune_t.h
source/list.o: /usr/include/sys/_types/_wchar_t.h
source/list.o: /usr/include/sys/_types/_null.h /usr/include/machine/types.h
source/list.o: /usr/include/i386/types.h /usr/include/sys/_types/_dev_t.h
source/list.o: /usr/include/sys/_types/_mode_t.h /usr/include/string.h
source/list.o: /usr/include/sys/_types/_rsize_t.h
source/list.o: /usr/include/sys/_types/_errno_t.h
source/list.o: /usr/include/sys/_types/_ssize_t.h /usr/include/strings.h
source/list.o: /usr/include/secure/_string.h /usr/include/secure/_common.h
source/list.o: include/list.h
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
