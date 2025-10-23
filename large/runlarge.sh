#!/bin/bash
mkdir -p out
../lab4 3000 100 0 0 0 100 > output_3000_100_0_0_0_100.txt
mv ptable.txt ptable_3000_100_0_0_0_100.txt
../lab4 3000 100 1 0 0 100 > output_3000_100_1_0_0_100.txt
mv ptable.txt ptable_3000_100_1_0_0_100.txt
../lab4 3000 100 0 1 0 100 > output_3000_100_0_1_0_100.txt
mv ptable.txt ptable_3000_100_0_1_0_100.txt
../lab4 3000 100 1 1 0 100 > output_3000_100_1_1_0_100.txt
mv ptable.txt ptable_3000_100_1_1_0_100.txt
../lab4 3000 100 0 2 0 100 > output_3000_100_0_2_0_100.txt
mv ptable.txt ptable_3000_100_0_2_0_100.txt
../lab4 3000 100 1 2 0 100 > output_3000_100_1_2_0_100.txt
mv ptable.txt ptable_3000_100_1_2_0_100.txt
../lab4 3000 100 0 3 0 100 > output_3000_100_0_3_0_100.txt
mv ptable.txt ptable_3000_100_0_3_0_100.txt
../lab4 3000 100 1 3 0 100 > output_3000_100_1_3_0_100.txt
mv ptable.txt ptable_3000_100_1_3_0_100.txt
../lab4 3000 100 0 0 1 100 > output_3000_100_0_0_1_100.txt
mv ptable.txt ptable_3000_100_0_0_1_100.txt
../lab4 3000 100 1 0 1 100 > output_3000_100_1_0_1_100.txt
mv ptable.txt ptable_3000_100_1_0_1_100.txt
../lab4 3000 100 0 1 1 100 > output_3000_100_0_1_1_100.txt
mv ptable.txt ptable_3000_100_0_1_1_100.txt
../lab4 3000 100 1 1 1 100 > output_3000_100_1_1_1_100.txt
mv ptable.txt ptable_3000_100_1_1_1_100.txt
../lab4 3000 100 0 2 1 100 > output_3000_100_0_2_1_100.txt
mv ptable.txt ptable_3000_100_0_2_1_100.txt
../lab4 3000 100 1 2 1 100 > output_3000_100_1_2_1_100.txt
mv ptable.txt ptable_3000_100_1_2_1_100.txt
../lab4 3000 100 0 3 1 100 > output_3000_100_0_3_1_100.txt
mv ptable.txt ptable_3000_100_0_3_1_100.txt
../lab4 3000 100 1 3 1 100 > output_3000_100_1_3_1_100.txt
mv ptable.txt ptable_3000_100_1_3_1_100.txt
mv ptable* output* out/.
