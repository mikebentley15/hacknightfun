#!/usr/bin/env python
'Script for finding the amount of unique houses visited in a given path'

import argparse
import sys

def main(arguments):
    'Main entry point'
    parser = argparse.ArgumentParser()
    parser.add_argument('pathfile', nargs='+', help='The path file for Santa (e.g. "^>^<<>^vv>>"')
    args = parser.parse_args(arguments)

    current = (0, 0)
    visits = set()
    visits.add(current)
    movements = {
        '^':  lambda x: (x[0], x[1]+1),
        'v':  lambda x: (x[0], x[1]-1),
        '<':  lambda x: (x[0]-1, x[1]),
        '>':  lambda x: (x[0]+1, x[1]),
        '\n': lambda x: x,
        }
    for filename in args.pathfile:
        with open(filename, 'r') as pathfile:
            for char in pathfile.read():
                try:
                    current = movements[char](current)
                    visits.add(current)
                except KeyError:
                    print 'Warning: unrecognized character:', char
    print '# Visited houses: ', len(visits)

if __name__ == '__main__':
    main(sys.argv[1:])

