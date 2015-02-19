#!bin/sh

infile="test.in"
outfile="test.out"
output=$(./a.out <"$infile")
echo "$output" > "$outfile"
