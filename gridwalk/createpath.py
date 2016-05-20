#!/usr/bin/env python
'Script for creating a random santa walk path of specified length'

import argparse
import sys
import random

def main(arguments):
    'Main entry point'
    parser = argparse.ArgumentParser()
    parser.add_argument('pathlen', type=int,
        help='The length of Santa path (e.g. 11 may give "^>^<<>^vv>>"')
    args = parser.parse_args(arguments)

    chars = ('^', 'v', '<', '>')
    for _ in xrange(args.pathlen):
        sys.stdout.write(random.choice(chars))
    print

if __name__ == '__main__':
    main(sys.argv[1:])

