CC=`which gcc`
GDB=`which cgdb`
CFLAGS=-ggdb -Wall
CWD=$(shell pwd)

.PHONY: cache build gdb clean run run_exec build_msg debug_msg end_msg
cache:
	echo $(MAKECMDGOALS) > CACHE 

build: clean cache build_msg 
	$(CC) $(CFLAGS) list.c

gdb: debug_msg 
	clear
	sudo $(GDB) a.out 

clean:
	clear
	rm -rf $(CWD)/a.out* CACHE

run: run_exec end_msg

build_msg:
	@printf "\n\n#------------------------------------------------------\n"
	@printf "# Building to a.out \n"
	@printf "#------------------------------------------------------\n\n"

debug_msg:
	@printf "\n\n#------------------------------------------------------\n"
	@printf "# Debugging a.out \n"
	@printf "#------------------------------------------------------\n\n"

run_exec:
	@printf "\n\n#------------------------------------------------------\n"
	@printf "RUNNING: "
	@cat CACHE	
	@printf "#------------------------------------------------------\n\n"
	$(CWD)/a.out

end_msg:
	@printf "\n\n\n"
