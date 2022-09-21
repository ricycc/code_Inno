#ifndef PROBLEM_1_H_
#define PROBLEM_1_H_

#include <cstddef>
#include <cstdint>
#include <vector>

class Solution1 {
 public:
  Solution1() {}
  ~Solution1() {}

  /// @brief return the number of paths rabbit in the top-left-most cell of a M
  /// x N grid can reach its home at the bottom-right-most cell
  /// @param M the size of rows of the grid
  /// @param N the size of cols of the grid
  /// @param cells the vector indicates where snakes are on the grid, 1 means
  /// snake is on this cell, 0 means this cell if free of snake
  /// @return the number of paths
  uint64_t GetNumberOfPaths1(
      const size_t M, const size_t N,
      const std::vector<std::pair<size_t, size_t>>& cells) const;

  /// @brief return the number of paths rabbit in the top-left-most cell of a M
  /// x N grid can reach its home at the bottom-right-most cell
  /// @param M the size of rows of the grid
  /// @param N the size of cols of the grid
  /// @param cells the vector indicates where snakes are on the grid, 1 means
  /// snake is on this cell, 0 means this cell if free of snake
  /// @return the number of paths
  uint64_t GetNumberOfPaths2(
      const size_t M, const size_t N,
      const std::vector<std::pair<size_t, size_t>>& cells) const;
};

#endif  // PROBLEM_1_H_
