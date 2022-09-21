#include "problem_1/problem_1.h"

#include <iostream>
#include <limits>
#include <set>

uint64_t Solution1::GetNumberOfPaths1(
    const size_t M, const size_t N,
    const std::vector<std::pair<size_t, size_t>>& cells) const {
  if (M == 0 || N == 0) {
    std::cout << "row or col size is 0!" << std::endl;
    return 0;
  }
  size_t t_max = std::numeric_limits<size_t>::max();
  auto s_max = std::vector<uint64_t>().max_size();
  std::cout << "t_max " << t_max << std::endl;
  std::cout << "s_max " << s_max << std::endl;
  if (M < 0 || M > t_max || N < 0 || N > t_max) {
    std::cout << "row or col size invlid!" << std::endl;
    return 0;
  }
  // use set to reduce time complexity
  std::set<std::pair<size_t, size_t>> st(cells.begin(), cells.end());
  // use a vector to store the number of paths to reach that cell
  std::vector<std::vector<uint64_t>> dp(M, std::vector<uint64_t>(N, 0));
  for (size_t i = 0; i < M; ++i) {
    for (size_t j = 0; j < N; ++j) {
      if (i == 0 && j == 0) {
        // the number of paths to reach the first cell is 1
        dp[i][j] = 1;
      } else if (st.count(std::make_pair(i, j)) == 0) {
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
    const std::vector<std::pair<size_t, size_t>>& cells) const {
  if (M == 0 || N == 0) {
    std::cout << "row or col size is 0!" << std::endl;
    return 0;
  }
  std::set<std::pair<size_t, size_t>> st(cells.begin(), cells.end());
  // use a vector to store the number of paths to reach that cell
  // use 1D vector to reduce space complexity
  std::vector<uint64_t> dp(std::min(M, N), 0);
  if (M <= N) {
    // dp by col when M <= N
    for (size_t j = 0; j < N; ++j) {
      for (size_t i = 0; i < M; ++i) {
        if (i == 0 && j == 0) {
          // the number of paths to reach the first cell is 1
          dp[i] = 1;
        } else if (st.count(std::make_pair(i, j)) == 0) {
          // only cell without snake can be reached
          if (j == 0) {
            // there is no left col of the first col
            dp[i] = dp[i - 1];
          } else if (i == 0) {
            // there is no upper row of the first row
            dp[i] = dp[i];
          } else {
            // number of paths to a "normal" cell is the sum of number of paths
            // to its left cell and number of paths to its upper cell
            dp[i] = dp[i - 1] + dp[i];
          }
        } else {
          // cell with snake can not be reached
          dp[i] = 0;
        }
      }
    }
  } else {
    // dp by row when M > N
    for (size_t i = 0; i < M; ++i) {
      for (size_t j = 0; j < N; ++j) {
        if (i == 0 && j == 0) {
          // the number of paths to reach the first cell is 1
          dp[j] = 1;
        } else if (st.count(std::make_pair(i, j)) == 0) {
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
  }
  return dp[std::min(M, N) - 1];
}