package(
  default_visibility = ["//visibility:public"],
)

cc_library(
  name = "problem_2",
  srcs = ["problem_2.cc"],
  hdrs = ["problem_2.h"],
)

cc_test(
  name = "test_problem_2",
  srcs = ["test_problem_2.cc"],
  deps = [
    ":problem_2",
    "@com_google_googletest//:gtest_main",
  ],
)