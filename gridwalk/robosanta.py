#!/usr/bin/env python
'Script for finding the amount of unique houses visited in a given path'

import argparse
import sys

def main(arguments):
    'Main entry point'
    parser = argparse.ArgumentParser()
    parser.add_argument('pathfile', nargs='+', help='The path file for Santa (e.g. "^>^<<>^vv>>"')
    args = parser.parse_args(arguments)

    santa = (0, 0)
    robo = (0, 0)
    visits = set()
    robovisits = set()
    visits.add(santa)
    robovisits.add(robo)
    movements = {
        '^':  lambda x: (x[0], x[1]+1),
        'v':  lambda x: (x[0], x[1]-1),
        '<':  lambda x: (x[0]-1, x[1]),
        '>':  lambda x: (x[0]+1, x[1]),
        '\n': lambda x: x,
        }
    isSantasTurn = True
    for filename in args.pathfile:
        with open(filename, 'r') as pathfile:
            for char in pathfile.read():
                try:
                    if isSantasTurn:
                        santa = movements[char](santa)
                        visits.add(santa)
                    else:
                        robo = movements[char](robo)
                        robovisits.add(robo)
                except KeyError:
                    print 'Warning: unrecognized character:', char
                isSantasTurn = not isSantasTurn
    print '# Visited houses by santa:      ', len(visits)
    print '# Visited houses by robo santa: ', len(robovisits)
    print '# Visited houses by both:       ', len(visits.union(robovisits))

if __name__ == '__main__':
    main(sys.argv[1:])

