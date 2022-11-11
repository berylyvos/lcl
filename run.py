#!/usr/bin/python3
# usage: 
#   ./run.py argv[1] argv[2], ...
#   /usr/bin/python3 ./run.py argv[1] argv[2], ...
import sys
import os
import subprocess

SRC_DIR = "./src/"
EXE_DIR = "./bin/"

def make_build_directory():
    if not os.path.isdir(EXE_DIR):
        os.mkdir(EXE_DIR)

def find_path(key):
    for fn in os.listdir(SRC_DIR):
        if fn.startswith(key):
            return SRC_DIR + fn + "/main.cpp"

def build(key, lt):
    make_build_directory()
    gxx_options = [
        "/usr/bin/g++", 
        "-Wall", "-g", "-O2", "-std=c++11",
        "-I", "./src",
        find_path(key),
        "-o", EXE_DIR + key 
    ]
    if lt == 'l':
        gxx_options.append("./src/common/list.cpp")
    elif lt == 't':
        gxx_options.append("./src/common/tree.cpp")

    print(" ".join(gxx_options))
    subprocess.run(gxx_options)

def run(key, lt):
    if not os.path.isfile(EXE_DIR + key):
        build(key, lt)
    assert(os.path.isdir(EXE_DIR))
    subprocess.run(EXE_DIR + key)


if __name__ == '__main__':
    n = len(sys.argv)
    assert(n >= 3)
    op = sys.argv[1].lower()
    id = sys.argv[2].lower()
    lk = sys.argv[3] if n > 3 else None

    if "b" == op:
        build(id, lk)
    elif "r" == op:
        run(id, lk)
    elif "br" == op:
        build(id, lk)
        run(id, lk)