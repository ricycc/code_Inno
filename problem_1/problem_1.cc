#include "problem_1/problem_1.h"

#include <algorithm>
#include <iostream>
#include <limits>

uint64_t Solution1::GetNumberOfPaths1(
    const size_t M, const size_t N,
    const std::vector<CellPosition>& snakes) const {
  if (M == 0 || N == 0) {
    std::cout << "row or col size is 0!" << std::endl;
    return 0;
  }
  size_t u_max = std::vector<uint64_t>().max_size();
  if (M < 0 || M > u_max || N < 0 || N > u_max) {
    std::cout << "row or col size invlid!" << std::endl;
    return 0;
  }
  // use a vector to store the number of paths to reach that cell
  std::vector<std::vector<uint64_t>> dp(M, std::vector<uint64_t>(N, 0));
  for (size_t i = 0; i < M; ++i) {
    for (size_t j = 0; j < N; ++j) {
      if (i == 0 && j == 0) {
        // the number of paths to reach the first cell is 1
        dp[i][j] = 1;
      } else if (std::find(snakes.begin(), snakes.end(), CellPosition(i, j)) ==
                 snakes.end()) {
        // only cell without snake can be reached
        if (i == 0) {
          // there is no left col of the first col
          dp[i][j] = dp[i][j - 1];
        } else if (j == 0) {
          // there is no upper row of the first row
          dp[i][j] = dp[i - 1][j];
        } else {
          // number of paths to a "normal" cell is the sum of number of paths to
          // its left cell and number of paths to its upper cell
          dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
        }
      } else {
        // cell with snake can not be reached
        dp[i][j] = 0;
      }
    }
  }
  return dp[M - 1][N - 1];
}

uint64_t Solution1::GetNumberOfPaths2(
    const size_t M, const size_t N,
    const std::vector<CellPosition>& snakes) const {
  if (M == 0 || N == 0) {
    std::cout << "row or col size is 0!" << std::endl;
    return 0;
  }
  size_t u_max = std::vector<uint64_t>().max_size();
  if (M < 0 || M > u_max || N < 0 || N > u_max) {
    std::cout << "row or col size invlid!" << std::endl;
    return 0;
  }
  // use a vector to store the number of paths to reach that cell
  // use 1D vector to reduce space complexity
  std::vector<uint64_t> dp(std::min(M, N), 0);
  // dp by row when M > N, by col when M <= N
  for (size_t i = 0; i < std::max(M, N); ++i) {
    for (size_t j = 0; j < std::min(M, N); ++j) {
      if (i == 0 && j == 0) {
        // the number of paths to reach the first cell is 1
        dp[j] = 1;
      } else if ((M <= N && std::find(snakes.begin(), snakes.end(),
                                      CellPosition(j, i)) == snakes.end()) ||
                 (M > N && std::find(snakes.begin(), snakes.end(),
                                     CellPosition(i, j)) == snakes.end())) {
        // only cell without snake can be reached
        if (i == 0) {
          // there is no left col of the first col
          dp[j] = dp[j - 1];
        } else if (j == 0) {
          // there is no upper row of the first row
          dp[j] = dp[j];
        } else {
          // number of paths to a "normal" cell is the sum of number of paths
          // to its left cell and number of paths to its upper cell
          dp[j] = dp[j - 1] + dp[j];
        }
      } else {
        // cell with snake can not be reached
        dp[j] = 0;
      }
    }
  }
  return dp[std::min(M, N) - 1];
}

std::vector<std::vector<CellPosition>> Solution1::GetPaths1(
    const size_t M, const size_t N, const std::vector<CellPosition>& snakes) {
  std::vector<std::vector<CellPosition>> paths;
  if (M == 0 || N == 0) {
    std::cout << "row or col size is 0!" << std::endl;
    return paths;
  }
  // vector size cannot be too large
  size_t u_max = std::vector<uint64_t>().max_size();
  if (M < 0 || M > u_max || N < 0 || N > u_max) {
    std::cout << "row or col size invlid!" << std::endl;
    return paths;
  }
  // set private parameters
  row_count_ = M;
  col_count_ = N;
  snakes_ = snakes;
  std::vector<CellPosition> temp_path;
  // call corresponding dfs function
  DfsPath1(0, 0, &temp_path, &paths);
  return paths;
}

void Solution1::DfsPath1(const size_t row, const size_t col,
                         std::vector<CellPosition>* temp_path,
                         std::vector<std::vector<CellPosition>>* paths) {
  if (nullptr == temp_path || nullptr == paths) {
    std::cout << "input nullptr!" << std::endl;
  }
  // return condition:
  // 1. row or col idx overflow, upper overflow in question A-D
  // 2. there is a snake in current cell
  if (row > row_count_ - 1 || col > col_count_ - 1 ||
      std::find(snakes_.begin(), snakes_.end(), CellPosition(row, col)) !=
          snakes_.end()) {
    return;
  }
  // add current cell to current path when return condition is not met
  temp_path->emplace_back(row, col);
  if (row == row_count_ - 1 && col == col_count_ - 1) {
    // add current path to results when target is reached
    paths->emplace_back(*temp_path);
  } else {
    // continue to do dfs when target is not reached
    DfsPath1(row + 1, col, temp_path, paths);
    DfsPath1(row, col + 1, temp_path, paths);
  }
}

std::vector<std::vector<CellPosition>> Solution1::GetPaths2(
    const size_t M, const size_t N, const std::vector<CellPosition>& snakes) {
  std::vector<std::vector<CellPosition>> paths;
  if (M == 0 || N == 0) {
    std::cout << "row or col size is 0!" << std::endl;
    return paths;
  }
  // vector size cannot be too large
  size_t u_max = std::vector<uint64_t>().max_size();
  if (M < 0 || M > u_max || N < 0 || N > u_max) {
    std::cout << "row or col size invlid!" << std::endl;
    return paths;
  }
  // set private parameters
  row_count_ = M;
  col_count_ = N;
  snakes_ = snakes;
  visited_ = std::vector<std::vector<bool>>(M, std::vector<bool>(N, false));
  std::vector<CellPosition> temp_path;
  // call corresponding dfs function
  DfsPath2(0, 0, &temp_path, &paths);
  return paths;
}

void Solution1::DfsPath2(const size_t row, const size_t col,
                         std::vector<CellPosition>* temp_path,
                         std::vector<std::vector<CellPosition>>* paths) {
  if (nullptr == temp_path || nullptr == paths) {
    std::cout << "input nullptr!" << std::endl;
  }
  // return condition:
  // 1. row or col idx overflow, both lower and upper overflow in question E
  // 2. the cell has been marked as visited
  // 3. there is a snake in current cell
  if (row < 0 || row > row_count_ - 1 || col < 0 || col > col_count_ - 1 ||
      visited_.at(row).at(col) ||
      std::find(snakes_.begin(), snakes_.end(), CellPosition(row, col)) !=
          snakes_.end()) {
    return;
  }
  // add current cell to current path when return condition is not met
  temp_path->emplace_back(row, col);
  // mark current cell as visited before continue
  visited_.at(row).at(col) = true;
  if (row == row_count_ - 1 && col == col_count_ - 1) {
    // add current path to results when target is reached
    paths->emplace_back(*temp_path);
  } else {
    // continue to do dfs when target is not reached
    DfsPath2(row - 1, col, temp_path, paths);
    DfsPath2(row, col - 1, temp_path, paths);
    DfsPath2(row + 1, col, temp_path, paths);
    DfsPath2(row, col + 1, temp_path, paths);
  }
  // unmark current cell as visited before return
  visited_.at(row).at(col) = false;
}