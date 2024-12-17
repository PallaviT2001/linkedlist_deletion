cmake_minimum_required(VERSION 3.16)

project(linkedlist_task_deletion LANGUAGES C)

add_executable(linkedlist_task_deletion main.c)

include(GNUInstallDirs)
install(TARGETS linkedlist_task_deletion
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
