#!/usr/bin/env python3
import os
import mmap
import subprocess
import sys


unused = """
set(library_sources

)

add_library( library ${library_sources} )
target_include_directories(library PRIVATE src)

add_executable(lang src/automaton641/lang/main.c )
target_include_directories(lang PRIVATE src)
target_link_libraries(lang library )
target_link_libraries(lang pthread)
target_link_libraries(lang GLEW)
target_link_libraries(lang GLU)
target_link_libraries(lang GL)
target_link_libraries(lang glfw)
"""

def find_sources(source_directory):
    sources = []
    for file in os.listdir(source_directory):
        if file.endswith(".c") or file.endswith(".h"):
            sources.append(os.path.join(source_directory, file))
    return sources

class Library:
    def __init__(self, name, dependecies = []):
        self.name = name
        self.dependecies = dependecies
        self.include_path = "./src/"
        self.source_directory = "./src/"
        self.tabs = 0
        self.sources = []
        self.linked_libraries = []
        self.build_type = "debug"
        self.makecontent = """
cmake_minimum_required(VERSION 3.13.4)
project (TheProject)
"""
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
    def run(self, target):
            build_directory = self.build_type
            isdir = os.path.isdir(build_directory) 
            if not isdir:
                print("[info] build directory'" + build_directory + "' not found...") 
                subprocess.run(["mkdir", build_directory])
                os.chdir(build_directory)
                if build_directory == "debug":
                    subprocess.run(["cmake", "-DCMAKE_BUILD_TYPE=Debug", ".."])
                else:
                    subprocess.run(["cmake", "-DCMAKE_BUILD_TYPE=Release", ".."])
                subprocess.run(["make"])
                os.chdir("..")
            self.makecontent += "set( " + self.name +"_sources\n"
            for source in self.sources:
                self.makecontent += source + "\n"
            self.makecontent += ")\n"
            self.makecontent += "add_library(" + self.name + " ${" + self.name + "_sources} )\n"
            self.makecontent += "target_include_directories( " + self.name + " PRIVATE " + self.include_path + " )\n"
            self.makecontent += "\n"
            target_sources_directory = self.include_path + "automaton641/" + target
            isdir = os.path.isdir(target_sources_directory) 
            if not isdir:
                print("[ERROR] target '" + target + "' not found...") 
                sys.exit()
            target_sources = find_sources(target_sources_directory)
            self.makecontent += "add_executable( " + target + "\n"
            for source in target_sources:
                self.makecontent += source + "\n"
            self.makecontent += ")\n"
            self.makecontent += "target_include_directories( " + target + " PRIVATE " + self.include_path + " )\n"
            self.makecontent += "target_link_libraries( " + target + " " + self.name + " )\n"
            for linked_library in self.linked_libraries:
                self.makecontent += "target_link_libraries( " + target + " " + linked_library + " )\n"
            filename = "CMakeLists.txt"
            myfile = open(filename, 'w')
            myfile.write(self.makecontent)
            myfile.close()
            os.chdir(self.build_type)
            print("[" + self.build_type + "] " + "building...")
            subprocess.run(["make"])
            print("[" + self.build_type + "] " + "...finished building")
            print("[" + self.build_type + "] " + "running...")
            os.chdir("..")
            subprocess.run([ "./" + self.build_type + "/" + target ])
            print("[" + self.build_type + "] " + "...finished running")

argc = len(sys.argv)
argv = sys.argv
build_types = ["debug", "release"]
library = Library("library")
library.source_directory += "automaton641/library/"
library.linked_libraries = ["pthread", "GLEW", "GLU", "GL", "glfw"]
library.find_sources()
target = "game"
if argc > 1:
    target = argv[1]
    if target == "clean":
        print("[clean] cleaning...")
        for build_directory in build_types:
            subprocess.run(["rm","-r",build_directory])
        sys.exit()
    if argc > 2:
        library.build_type = argv[2]
        if not library.build_type in build_types:
            print("invalid build type")
            sys.exit()


library.run(target)