#ifndef PROBLEM_1_PROBLEM_1_H_
#define PROBLEM_1_PROBLEM_1_H_

#include <cstddef>
#include <cstdint>
#include <vector>

struct CellPosition {
  CellPosition(const size_t r, const size_t c) {
    row_num = r;
    col_num = c;
  }
  
  bool operator==(const CellPosition& rhs) const {
    return row_num == rhs.row_num && col_num == rhs.col_num;
  }

  size_t row_num = 0u;
  size_t col_num = 0u;
};

class Solution1 {
 public:
  Solution1() {}
  ~Solution1() {}

  /// @brief return the number of paths rabbit in the top-left-most cell of a M
  /// x N grid can reach its home at the bottom-right-most cell
  /// @param M the size of rows of the grid
  /// @param N the size of cols of the grid
  /// @param snakes the vector indicates where snakes are on the grid
  /// @return the number of paths
  uint64_t GetNumberOfPaths1(const size_t M, const size_t N,
                             const std::vector<CellPosition>& snakes) const;

  /// @brief return the number of paths rabbit in the top-left-most cell of a M
  /// x N grid can reach its home at the bottom-right-most cell
  /// @param M the size of rows of the grid
  /// @param N the size of cols of the grid
  /// @param snakes the vector indicates where snakes are on the grid
  /// @return the number of paths
  uint64_t GetNumberOfPaths2(const size_t M, const size_t N,
                             const std::vector<CellPosition>& snakes) const;

  /// @brief return all the paths rabbit in the top-left-most cell of a M x N
  /// grid can reach its home at the bottom-right-most cell, Answer to question D
  /// @param M the size of rows of the grid
  /// @param N the size of cols of the grid
  /// @param snakes the vector indicates where snakes are on the grid
  /// @return the vector of paths
  std::vector<std::vector<CellPosition>> GetPaths1(
      const size_t M, const size_t N,
      const std::vector<CellPosition>& snakes);

  /// @brief return all the paths rabbit in the top-left-most cell of a M x N
  /// grid can reach its home at the bottom-right-most cell, Answer to question E
  /// @param M the size of rows of the grid
  /// @param N the size of cols of the grid
  /// @param snakes the vector indicates where snakes are on the grid
  /// @return the vector of paths
  std::vector<std::vector<CellPosition>> GetPaths2(
      const size_t M, const size_t N,
      const std::vector<CellPosition>& snakes);

 private:
  /// @brief dfs solution to question D
  /// @param row current row nunber of dfs
  /// @param col current col number of dfs
  /// @param temp_path current path to this cell
  /// @param paths result paths
  void DfsPath1(const size_t row,
               const size_t col, std::vector<CellPosition>* temp_path,
               std::vector<std::vector<CellPosition>>* paths);

  /// @brief dfs solution to question E
  /// @param row current row nunber of dfs
  /// @param col current col number of dfs
  /// @param temp_path current path to this cell
  /// @param paths result paths
  void DfsPath2(const size_t row,
               const size_t col, std::vector<CellPosition>* temp_path,
               std::vector<std::vector<CellPosition>>* paths);

 private:
  // store some information for question D, positions of snakes
  std::vector<CellPosition> snakes_;
  // count of rows
  size_t row_count_ = 0u;
  // count of cols
  size_t col_count_ = 0u;
  // store cell visited_ information for question E
  std::vector<std::vector<bool>> visited_;
};

#endif  // PROBLEM_1_PROBLEM_1_H_
