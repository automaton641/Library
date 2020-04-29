#!/usr/bin/env python3
import subprocess
import os
subprocess.run(["mkdir", "release"])
os.chdir("release")
subprocess.run(["cmake", "-DCMAKE_BUILD_TYPE=Release", ".."])
subprocess.run(["make"])