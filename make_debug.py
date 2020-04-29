#!/usr/bin/env python3
import subprocess
import os
subprocess.run(["mkdir", "debug"])
os.chdir("debug")
subprocess.run(["cmake", "-DCMAKE_BUILD_TYPE=Debug", ".."])
subprocess.run(["make"])