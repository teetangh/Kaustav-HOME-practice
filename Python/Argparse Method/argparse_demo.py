import math
import argparse

parser = argparse.ArgumentParser(
    description='Calculate the volume of a Cylinder')
parser.add_argument('-r', '--radius', type=int, metavar='',
                    required=True, help='Radius of a Cylinder')
parser.add_argument('-H', '--height', type=int, metavar='',
                    required=True, help='Height of a Cylinder')

groups = parser.add_mutually_exclusive_group()
groups.add_argument('-q', '--quiet', action='store_true', help='print quiet')
groups.add_argument('-v', '--verbose', action='store_true',
                    help='print verbose')

args = parser.parse_args()


def cylinder_volume(radius, height):
    vol = (math.pi) * (radius ** 2) * height
    return vol


if __name__ == "__main__":
    volume = cylinder_volume(args.radius, args.height)

    if args.quiet:
        print(volume)
    elif args.verbose:
        print(" Volume of a Cylinder with radius %s and height %s is %s " %
              (args.radius, args.height, volume))
    else:
        print("Volume of the Cylinder = %s" % volume)


# python.exe .\argparse_demo.py -h
# python.exe .\argparse_demo.py -q -r 3 -H 4
# python.exe .\argparse_demo.py -v -r 3 -H 4

# usage: argparse_demo.py [-h] -r  -H

# Calculate the volume of a Cylinder

# optional arguments:
#   -h, --help      show this help message and exit
#   -r , --radius   Radius of a Cylinder
#   -H , --height   Height of a Cylinder
