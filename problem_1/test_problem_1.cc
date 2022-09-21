#include <gtest/gtest.h>

#include "problem_1/problem_1.h"

TEST(Solution1, GetNumberOfPathsTest) {
  Solution1 sol;
  std::vector<CellPosition> pro0;
  EXPECT_EQ(0, sol.GetNumberOfPaths1(0, 0, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(0, 0, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(0, 8, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(0, 8, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(8, 0, pro0));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(8, 0, pro0));
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
  std::vector<CellPosition> pro1{{0, 1}};
  EXPECT_EQ(1, sol.GetNumberOfPaths1(2, 2, pro1));
  EXPECT_EQ(1, sol.GetNumberOfPaths2(2, 2, pro1));
  std::vector<CellPosition> pro2{{0, 2}};
  EXPECT_EQ(2, sol.GetNumberOfPaths1(2, 3, pro2));
  EXPECT_EQ(2, sol.GetNumberOfPaths2(2, 3, pro2));
  std::vector<CellPosition> pro3{{0, 2}};
  EXPECT_EQ(5, sol.GetNumberOfPaths1(3, 3, pro3));
  EXPECT_EQ(5, sol.GetNumberOfPaths2(3, 3, pro3));
  EXPECT_EQ(11, sol.GetNumberOfPaths1(3, 6, pro3));
  EXPECT_EQ(11, sol.GetNumberOfPaths2(3, 6, pro3));
  EXPECT_EQ(20, sol.GetNumberOfPaths1(6, 3, pro3));
  EXPECT_EQ(20, sol.GetNumberOfPaths2(6, 3, pro3));
  std::vector<CellPosition> pro4{{0, 2}, {1, 1}, {2, 0}};
  EXPECT_EQ(0, sol.GetNumberOfPaths1(3, 3, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(3, 3, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(3, 4, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(3, 4, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths1(4, 4, pro4));
  EXPECT_EQ(0, sol.GetNumberOfPaths2(4, 4, pro4));
}

TEST(Solution1, GetPaths1Test) {
  Solution1 sol;
  std::vector<CellPosition> pro0;
  EXPECT_EQ(0, sol.GetPaths1(0, 0, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(0, 0, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(0, 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(0, 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(8, 0, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(8, 0, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(-1, 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(-1, 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(8, -1, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(8, -1, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(
                   std::numeric_limits<unsigned long long>::max(), 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(
                   std::numeric_limits<unsigned long long>::max(), 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(
                   8, std::numeric_limits<unsigned long long>::max(), pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(
                   8, std::numeric_limits<unsigned long long>::max(), pro0).size());
  std::vector<CellPosition> pro1{{0, 1}};
  auto paths = sol.GetPaths1(2, 2, pro1);
  EXPECT_EQ(1, paths.size());
  // for (auto& path:paths) {
  //   std::cout << "paths " << std::endl;
  //   for (auto& p:path) {
  //     std::cout << "p.r " << p.row_num << " p.c " << p.col_num << std::endl;
  //   }
  // }
  std::vector<CellPosition> pro2{{0, 2}};
  paths = sol.GetPaths1(2, 3, pro2);
  EXPECT_EQ(paths.size(), 2);
  std::vector<CellPosition> pro3{{0, 2}};
  paths = sol.GetPaths1(3, 3, pro3);
  EXPECT_EQ(paths.size(), 5);
  paths = sol.GetPaths1(3, 6, pro3);
  EXPECT_EQ(paths.size(), 11);
  paths = sol.GetPaths1(6, 3, pro3);
  EXPECT_EQ(paths.size(), 20);
  std::vector<CellPosition> pro4{{0, 2}, {1, 1}, {2, 0}};
  paths = sol.GetPaths1(3, 3, pro4);
  EXPECT_EQ(paths.size(), 0);
  paths = sol.GetPaths1(3, 4, pro4);
  EXPECT_EQ(paths.size(), 0);
  paths = sol.GetPaths1(4, 3, pro4);
  EXPECT_EQ(paths.size(), 0);
}

TEST(Solution1, GetPaths2Test) {
  Solution1 sol;
  std::vector<CellPosition> pro0;
  EXPECT_EQ(0, sol.GetPaths1(0, 0, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(0, 0, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(0, 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(0, 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(8, 0, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(8, 0, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(-1, 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(-1, 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(8, -1, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(8, -1, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(
                   std::numeric_limits<unsigned long long>::max(), 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(
                   std::numeric_limits<unsigned long long>::max(), 8, pro0).size());
  EXPECT_EQ(0, sol.GetPaths1(
                   8, std::numeric_limits<unsigned long long>::max(), pro0).size());
  EXPECT_EQ(0, sol.GetPaths2(
                   8, std::numeric_limits<unsigned long long>::max(), pro0).size());
  std::vector<CellPosition> pro1{{0, 1}};
  auto paths = sol.GetPaths2(2, 2, pro1);
  EXPECT_EQ(1, paths.size());
  // for (auto& path:paths) {
  //   std::cout << "paths " << std::endl;
  //   for (auto& p:path) {
  //     std::cout << "p.r " << p.row_num << " p.c " << p.col_num << std::endl;
  //   }
  // }
  std::vector<CellPosition> pro2{{0, 2}};
  paths = sol.GetPaths2(2, 3, pro2);
  EXPECT_EQ(paths.size(), 2);
  std::vector<CellPosition> pro3{{0, 2}};
  paths = sol.GetPaths2(3, 3, pro3);
  EXPECT_EQ(paths.size(), 7);
  paths = sol.GetPaths2(3, 6, pro3);
  EXPECT_EQ(paths.size(), 147);
  paths = sol.GetPaths2(6, 3, pro3);
  EXPECT_EQ(paths.size(), 234);
  std::vector<CellPosition> pro4{{0, 2}, {1, 1}, {2, 0}};
  paths = sol.GetPaths2(3, 3, pro4);
  EXPECT_EQ(paths.size(), 0);
  paths = sol.GetPaths2(3, 4, pro4);
  EXPECT_EQ(paths.size(), 0);
  paths = sol.GetPaths2(4, 3, pro4);
  EXPECT_EQ(paths.size(), 0);
}