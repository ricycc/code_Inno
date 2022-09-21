#include <gtest/gtest.h>

#include "problem_2/problem_2.h"

TEST(Solution2, GetPairOfStonesTest) {
  Solution2 sol;
  std::vector<uint64_t> stones0{1, 0, 7, 3, 11};
  std::pair<size_t, size_t> stone_pair;
  bool ret = false;
  ret = sol.GetPairOfStones(stones0, 6, &stone_pair);
  EXPECT_FALSE(ret);
  ret = sol.GetPairOfStones(stones0, 6, nullptr);
  EXPECT_FALSE(ret);

  std::vector<uint64_t> stones1{1, 5, 7, 3, 11};
  ret = sol.GetPairOfStones(stones1, 8, &stone_pair);
  EXPECT_TRUE(ret);
  EXPECT_EQ(stone_pair.first, 4);
  EXPECT_EQ(stone_pair.second, 3);
  ret = sol.GetPairOfStones(stones1, 3, &stone_pair);
  EXPECT_FALSE(ret);

  std::vector<uint64_t> stones2{1, 5, 6, 5, 11};
  ret = sol.GetPairOfStones(stones2, 0, &stone_pair);
  EXPECT_TRUE(ret);
  EXPECT_EQ(stone_pair.first, 3);
  EXPECT_EQ(stone_pair.second, 1);
  ret = sol.GetPairOfStones(stones2, 6, &stone_pair);
  EXPECT_TRUE(ret);
  EXPECT_EQ(stone_pair.first, 4);
  EXPECT_EQ(stone_pair.second, 1);

  std::vector<uint64_t> stones3{1, 5, 6, 5, 11};
  stones3.at(0) = -1;
  ret = sol.GetPairOfStones(stones3, 6, &stone_pair);
  EXPECT_TRUE(ret);
  EXPECT_EQ(stone_pair.first, 4);
  EXPECT_EQ(stone_pair.second, 1);

  std::vector<uint64_t> stones4{1, 5, 18446744073709551615ul, 5, 11};
  ret = sol.GetPairOfStones(stones4, 18446744073709551615ul, &stone_pair);
  EXPECT_FALSE(ret);
  ret = sol.GetPairOfStones(stones4, 18446744073709551614ul, &stone_pair);
  EXPECT_TRUE(ret);
  EXPECT_EQ(stone_pair.first, 2);
  EXPECT_EQ(stone_pair.second, 0);
}

TEST(Solution2, GetPairsOfStonesTest) {
  Solution2 sol;
  std::vector<uint64_t> stones0{1, 0, 7, 3, 11};
  std::pair<size_t, size_t> stone_pair;
  std::vector<std::pair<size_t, size_t>> ret;
  ret = sol.GetPairsOfStones(stones0, 6);
  EXPECT_EQ(ret.size(), 0);

  std::vector<uint64_t> stones1{1, 5, 7, 3, 11};
  ret.clear();
  ret = sol.GetPairsOfStones(stones1, 8);
  EXPECT_EQ(ret.size(), 1);
  EXPECT_EQ(ret[0].first, 4);
  EXPECT_EQ(ret[0].second, 3);
  ret.clear();
  ret = sol.GetPairsOfStones(stones1, 2);
  EXPECT_EQ(ret.size(), 3);

  std::vector<uint64_t> stones2{1, 5, 6, 5, 11, 11};
  ret.clear();
  ret = sol.GetPairsOfStones(stones2, 0);
  EXPECT_EQ(ret.size(), 2);
  EXPECT_EQ(ret[0].first, 4);
  EXPECT_EQ(ret[0].second, 5);
  EXPECT_EQ(ret[1].first, 1);
  EXPECT_EQ(ret[1].second, 3);
  ret.clear();
  ret = sol.GetPairsOfStones(stones2, 6);
  EXPECT_EQ(ret.size(), 4);
  EXPECT_EQ(ret[0].first, 4);
  EXPECT_EQ(ret[0].second, 1);
  EXPECT_EQ(ret[1].first, 4);
  EXPECT_EQ(ret[1].second, 3);

  std::vector<uint64_t> stones3{1, 5, 6, 5, 11};
  stones3.at(0) = -1;
  ret.clear();
  ret = sol.GetPairsOfStones(stones3, 6);
  EXPECT_EQ(ret.size(), 2);
  EXPECT_EQ(ret[0].first, 4);
  EXPECT_EQ(ret[0].second, 1);

  std::vector<uint64_t> stones4{1, 5, 18446744073709551615ul, 5, 11};
  ret.clear();
  ret = sol.GetPairsOfStones(stones4, 18446744073709551615ul);
  EXPECT_EQ(ret.size(), 0);
  ret.clear();
  ret = sol.GetPairsOfStones(stones4, 18446744073709551614ul);
  EXPECT_EQ(ret.size(), 1);
  EXPECT_EQ(ret[0].first, 2);
  EXPECT_EQ(ret[0].second, 0);
}
