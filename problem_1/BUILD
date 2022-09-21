package(
  default_visibility = ["//visibility:public"],
)

cc_library(
  name = "problem_1",
  srcs = ["problem_1.cc"],
  hdrs = ["problem_1.h"],
)

cc_test(
  name = "test_problem_1",
  srcs = ["test_problem_1.cc"],
  deps = [
    ":problem_1",
    "@com_google_googletest//:gtest_main",
  ],
)