#!/bin/python

import sys

def minimumTime(x):
    a = 0
    b = 1000000000
    for i in x :
        if a < i :
            a = i
        if b > i :
            b = i
    return  a - b

if __name__ == "__main__":
    t = int(raw_input().strip())
    for a0 in xrange(t):
        n = int(raw_input().strip())
        x = map(int, raw_input().strip().split(' '))
        result = minimumTime(x)
        print result

