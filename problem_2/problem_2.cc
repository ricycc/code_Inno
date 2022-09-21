#include "problem_2/problem_2.h"

#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <utility>

bool Solution2::GetPairOfStones(const std::vector<uint64_t>& stones,
                                const uint64_t D,
                                std::pair<size_t, size_t>* stone_pair) const {
  if (nullptr == stone_pair) {
    std::cout << "input nullptr!" << std::endl;
    return false;
  }
  std::unordered_map<uint64_t, size_t> weight_idx_map;
  for (size_t i = 0; i < stones.size(); ++i) {
    if (stones.at(i) <= 0) {
      std::cout << "stones cannot weight 0 or negative!" << std::endl;
      return false;
    }
    // avoid low weight lower than 0
    if (stones.at(i) > D) {
      uint64_t low_weight = stones.at(i) - D;
      if (weight_idx_map.count(low_weight) != 0 &&
          weight_idx_map.at(low_weight) != i) {
        stone_pair->first = i;
        stone_pair->second = weight_idx_map.at(low_weight);
        return true;
      } else {
        // emplace wont change value of a key if it already exists
        weight_idx_map.emplace(stones.at(i), i);
      }
    }
    // use minus to avoid overflow
    if (std::numeric_limits<uint64_t>::max() - stones.at(i) >= D) {
      uint64_t high_weight = stones.at(i) + D;
      if (weight_idx_map.count(high_weight) != 0 &&
          weight_idx_map.at(high_weight) != i) {
        stone_pair->first = i;
        stone_pair->second = weight_idx_map.at(high_weight);
        return true;
      } else {
        weight_idx_map.emplace(stones.at(i), i);
      }
    }
  }
  return false;
}

std::vector<std::pair<size_t, size_t>> Solution2::GetPairsOfStones(
    const std::vector<uint64_t>& stones, const uint64_t D) const {
  std::vector<std::pair<size_t, size_t>> ret;
  std::unordered_map<uint64_t, std::vector<size_t>> weight_idxs_map;
  std::unordered_map<uint64_t, bool> weight_visited_map;
  for (size_t i = 0; i < stones.size(); ++i) {
    if (stones.at(i) <= 0) {
      std::cout << "stones cannot weight 0 or negative!" << std::endl;
      return ret;
    }
    weight_idxs_map[stones.at(i)].emplace_back(i);
    weight_visited_map[stones.at(i)] = false;
  }
  // special process when difference is 0
  if (D == 0) {
    for (const auto& weight_idxs : weight_idxs_map) {
      for (size_t i = 0; i < weight_idxs.second.size(); ++i) {
        for (size_t j = i + 1; j < weight_idxs.second.size(); ++j) {
          ret.emplace_back(std::make_pair(weight_idxs.second.at(i),
                                          weight_idxs.second.at(j)));
        }
      }
    }
    return ret;
  }
  for (const auto& weight_idxs : weight_idxs_map) {
    // avoid low weight lower than 0
    if (weight_idxs.first > D) {
      uint64_t low_weight = weight_idxs.first - D;
      if (low_weight != weight_idxs.first &&
          weight_idxs_map.count(low_weight) != 0 &&
          !weight_visited_map.at(low_weight)) {
        // generate pairs when target weight has not been used
        GeneratePairs(weight_idxs.second, weight_idxs_map.at(low_weight), &ret);
        weight_visited_map.at(weight_idxs.first) = true;
      }
    }
    // use minus to avoid overflow
    if (std::numeric_limits<uint64_t>::max() - weight_idxs.first >= D) {
      uint64_t high_weight = weight_idxs.first + D;
      if (weight_idxs_map.count(high_weight) != 0 &&
          !weight_visited_map.at(high_weight)) {
        // generate pairs when target weight has not been used
        GeneratePairs(weight_idxs.second, weight_idxs_map.at(high_weight),
                      &ret);
        weight_visited_map.at(weight_idxs.first) = true;
      }
    }
  }
  return ret;
}

void Solution2::GeneratePairs(
    const std::vector<size_t>& idxs1, const std::vector<size_t>& idxs2,
    std::vector<std::pair<size_t, size_t>>* ret) const {
  if (nullptr == ret) {
    std::cout << "input nullptr!" << std::endl;
    return;
  }
  for (const auto idx1 : idxs1) {
    for (const auto idx2 : idxs2) {
      ret->emplace_back(std::make_pair(idx1, idx2));
    }
  }
}
