cmake_minimum_required(VERSION 3.6)
#cmake_minimum_required(VERSION 3.5.1)
project(algorithms_c)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/out/Debug")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c89")

include_directories(include)

set(SOURCE_FILES_LIST
        examples/list/ex-1.c
        include/list.h
        include/utils.h
        source/list.c
        source/utils.c
        )

set(SOURCE_FILES_CLIST
        examples/clist/ex-1.c
        include/clist.h
        include/utils.h
        source/clist.c
        source/utils.c
        )

set(SOURCE_FILES_CLIST2
        examples/clist/ex-2.c
        include/clist.h
        include/page.h
        include/utils.h
        source/clist.c
        source/page.c
        source/utils.c
        )

set(SOURCE_FILES_DLIST
        examples/dlist/ex-1.c
        include/dlist.h
        include/utils.h
        source/dlist.c
        source/utils.c
        )

set(SOURCE_FILES_PQUEUE
        examples/pqueue/ex-1.c
        include/pqueue.h
        include/heap.h
        include/utils.h
        source/heap.c
        source/utils.c
        )

add_executable(list.out ${SOURCE_FILES_LIST})
add_executable(clist.out ${SOURCE_FILES_CLIST})
add_executable(clist2.out ${SOURCE_FILES_CLIST2})
add_executable(dlist.out ${SOURCE_FILES_DLIST})
add_executable(pqueue.out ${SOURCE_FILES_PQUEUE})



