#!/usr/bin/env python3
import os
import mmap
import subprocess


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
        self.sub_projects = []
        self.include_path = "./src/"
        self.source_directory = "./src/"
        self.tabs = 0
        self.sources = []
        self.linked_libraries = []
        self.out_directory = "out/"
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
            self.makecontent += "set( " + self.name +"_sources\n"
            for source in self.sources:
                self.makecontent += source + "\n"
            self.makecontent += ")\n"
            self.makecontent += "add_library(" + self.name + " ${" + self.name + "_sources} )\n"
            self.makecontent += "target_include_directories( " + self.name + " PRIVATE " + self.include_path + " )\n"
            for sub_project in self.sub_projects:
                self.makecontent += "\n"
                sub_project_sources = find_sources(self.include_path + "automaton641/" + sub_project)
                self.makecontent += "add_executable( " + sub_project + "\n"
                for source in sub_project_sources:
                    self.makecontent += source + "\n"
                self.makecontent += ")\n"
                self.makecontent += "target_include_directories( " + sub_project + " PRIVATE " + self.include_path + " )\n"
                self.makecontent += "target_link_libraries( " + sub_project + " " + self.name + " )\n"
                for linked_library in self.linked_libraries:
                    self.makecontent += "target_link_libraries( " + sub_project + " " + linked_library + " )\n"
            filename = "CMakeLists.txt"
            # Open the file with writing permission
            myfile = open(filename, 'w')
            # Write a line to the file
            myfile.write(self.makecontent)
            # Close the file
            myfile.close()
            #os.chdir("./build") 
            os.chdir(self.out_directory)
            print("building...")
            subprocess.run(["make"])
            print("...finished building")
            print("running...")
            os.chdir("..")
            subprocess.run([ "./" + self.out_directory + target ])
            print("...finished running")

library = Library("library")
library.source_directory += "automaton641/library/"
library.sub_projects = ["gui", "lang", "test"]
library.linked_libraries = ["pthread", "GLEW", "GLU", "GL", "glfw"]
library.find_sources()
library.run("gui")