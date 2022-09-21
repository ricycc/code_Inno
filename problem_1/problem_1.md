# Problem 1, Rabbit goes home

## question A

I create a class Solution1 for Problem1, the function to question A is Solution1::GetNumberOfPaths1. The time and space complexity of this function are both O(M*N).

## question B

The refined version of my function is Solution1::GetNumberOfPaths2. I use one dimension vector to store the dp results.

## question C

The corner cases are tested in test_problem_1.cc, mainly overflow cases.

## question D

I will use DFS to find all the paths, the answer is Solution1::GetPaths1.

## question E

This question requires we mark the cell we have already visited, the answer is Solution1::GetPaths2.
