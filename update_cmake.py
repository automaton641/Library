#!/usr/bin/env python3
import os
import mmap

MAKECONTENT = """ 
cmake_minimum_required(VERSION 3.13.4)
project (TheProject)

set(LIBRARY_SOURCES

)
add_library( Library ${LIBRARY_SOURCES} )
target_include_directories(Library PRIVATE src)

#add_library(lang_lib libsrc1.cc libsrc2.cc libsrc3.cc)
add_executable(lang src/automaton641/lang/main.c )
target_link_libraries(lang Library )
target_include_directories(lang PRIVATE src)
target_link_libraries(lang pthread)
target_link_libraries(lang GLEW)
target_link_libraries(lang GLU)
target_link_libraries(lang GL)
target_link_libraries(lang glfw)
"""

class Project:
    def __init__(self, name, dependecies = []):
        self.name = name
        self.dependecies = dependecies
        self.include_path = "./src/"
        self.source_directory = "./src/"
        self.tabs = 0
        self.sources = []
        self.linked_librarys = []
    def __str__(self):
        description = ""
        for i in range(self.tabs):
            description += "\t"
        description += "Project: " + self.name +"\n"
        for i in range(self.tabs):
            description += "\t"
        description += "Dependencies: " + "[\n"
        
        for project in self.dependecies:
            project.tabs = self.tabs + 1
            description += str(project) + "\n"
            project.tabs = 0
        for i in range(self.tabs):
            description += "\t"
        description += "],"
        return description;
    def find_sources(self):
        for file in os.listdir(self.source_directory):
            if file.endswith(".c") or file.endswith(".h"):
                self.sources.append(os.path.join(self.source_directory, file))
    def build(self):
            index = MAKECONTENT.index('set(LIBRARY_SOURCES')
            iterate = True
            while (iterate):
                if(MAKECONTENT[index] == '\n'):
                    iterate = False
                index += 1
            sources_string = ""
            for source in self.sources:
                sources_string += source + "\n"
            new_content = MAKECONTENT[:index] + sources_string + MAKECONTENT[index:]
            filename = "CMakeLists.txt"
            # Open the file with writing permission
            myfile = open(filename, 'w')
            # Write a line to the file
            myfile.write(new_content)
            # Close the file
            myfile.close()
library = Project("library")
library.source_directory += "automaton641/library/"
library.find_sources()
library.build()