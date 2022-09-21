#include <gtest/gtest.h>

#include "problem_1/problem_1.h"

TEST(Solution1, SolveTest) {
  Solution1 sol;
  std::vector<std::pair<size_t, size_t>> pro0;
  EXPECT_EQ(0, sol.GetNumberOfPaths1(0, 0, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(0, 0, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(0, 8, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(0, 8, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(8, 0, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(8, 0, pro0));
  // has to change vector to c array to pass overflow test
  EXPECT_EQ(0, sol.GetNumberOfPaths1(-1, 8, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(-1, 8, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(8, -1, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(8, -1, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(
                   std::numeric_limits<unsigned long long>::max(), 8, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(
                   std::numeric_limits<unsigned long long>::max(), 8, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(
                   8, std::numeric_limits<unsigned long long>::max(), pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(
                   8, std::numeric_limits<unsigned long long>::max(), pro0));
  std::vector<std::pair<size_t, size_t>> pro1{{0, 1}};
  EXPECT_EQ(1, sol.GetNumberOfPaths1(2, 2, pro1));
  EXPECT_EQ(1, sol.GetNumberOfPaths2(2, 2, pro1));
  std::vector<std::pair<size_t, size_t>> pro2{{0, 2}};
  EXPECT_EQ(2, sol.GetNumberOfPaths1(2, 3, pro2));
  EXPECT_EQ(2, sol.GetNumberOfPaths2(2, 3, pro2));
  std::vector<std::pair<size_t, size_t>> pro3{{0, 2}};
  EXPECT_EQ(5, sol.GetNumberOfPaths1(3, 3, pro3));
  EXPECT_EQ(5, sol.GetNumberOfPaths2(3, 3, pro3));
  std::vector<std::pair<size_t, size_t>> pro4{{0, 2}, {1, 1}, {2, 0}};
  EXPECT_EQ(0, sol.GetNumberOfPaths1(3, 3, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(3, 3, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(3, 4, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(3, 4, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(4, 4, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(4, 4, pro4));
}