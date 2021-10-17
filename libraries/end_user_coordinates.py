#!/usr/bin/python3
from linearalgebra import Cartesian


try:
    a = Cartesian(4, 9, 7)
    print(a)
except Exception:
    print("Sorry, I don't know what happens!")
