# Problem 2, Find stone pair(s)

## question A

Write a function F that:

- inputs:
  - data structure that repesents N number of stones, labeled as [0, N-1], and the weight of each of them
  - non-negative integer D
  - pointer of one pair of labels of stones, whose weight difference is D
- output: boolean to represent wether stone pair(s) is sucessfully found

## question B

- My answer to question A is Solution2::GetPairOfStones.
- The space complexity of my algorithm is O(N), time complexity is O(N)
- Yes
- Test program is test_problem_2.cc
  - a. All in my program
  - b. The stone pair should be checked when return is true. You just take the stone pair, first check if they are all within the labels, then take corresponding weight, use the larger one to minus the smaller one, check if the difference euqals D. When there is a pair of stone meets the requirement and the return is false, you know the function is cannot process these corner cases correctly.

## question C

