#!/usr/bin/env python3
"""Rebuild a full binary from a linked payload plus its original header/trailer.

    stitch.py <payload.bin> <head> <tail|-> <out>
"""
import sys

payload, head, tail, out = sys.argv[1:]
data = open(head, "rb").read() + open(payload, "rb").read()
if tail != "-":
    data += open(tail, "rb").read()
open(out, "wb").write(data)
