"""
py.

Vignesh Manoharan
"""
import sys
lines = sys.stdin.readline()
a = int(lines[0])
b = int(lines[1])

if a > b:
    print(">")
elif a < b:
    print("<")
else:
    print("=")
