#ifndef PROBLEM_2_PROBLEM_2_H_
#define PROBLEM_2_PROBLEM_2_H_

#include <cstddef>
#include <cstdint>
#include <vector>

class Solution2 {
 public:
  Solution2() {}
  ~Solution2() {}

  /// @brief get one pair of stones whose weight difference is D
  /// @param stones vector to store weights of stones, with idx as labels
  /// @param D the difference of weights to search
  /// @param stone_pair returned pair of stones, meaningless when function
  /// return false
  /// @return wether the pair of stones can be found
  bool GetPairOfStones(const std::vector<uint64_t>& stones, const uint64_t D,
                       std::pair<size_t, size_t>* stone_pair) const;

  /// @brief get all pairs of stones whose weight difference is D
  /// @param stones vector to store weights of stones, with idx as labels
  /// @param D the difference of weights to search
  /// @return pairs of stones, size 0 means not found
  std::vector<std::pair<size_t, size_t>> GetPairsOfStones(
      const std::vector<uint64_t>& stones, const uint64_t D) const;

 private:
  /// @brief generate pairs using two vector of idxs, avoiding dupicate
  /// @param idxs1 the first vector if idxs
  /// @param idxs2 the second vector of idxs
  /// @param ret the vector of pair of idxs, output pointer
  void GeneratePairs(const std::vector<size_t>& idxs1,
                     const std::vector<size_t>& idxs2,
                     std::vector<std::pair<size_t, size_t>>* ret) const;
};

#endif  // PROBLEM_2_PROBLEM_2_H_
