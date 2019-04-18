// A sample program demonstrating using Google C++ testing framework.

// This sample shows how to write a simple unit test for a function,
// using Google C++ testing framework.
//
// Writing a unit test using Google C++ testing framework is easy as 1-2-3:


// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.

#include <limits.h>
#include "bowling_game.h"
#include "gtest/gtest.h"
namespace {

// To use a test fixture, derive a class from testing::Test.
class BowlingGameTest : public testing::Test {
 protected:  // You should make the members protected s.t. they can be
             // accessed from sub-classes.

  // virtual void SetUp() will be called before each test is run.  
  // You should define it if you need to initialize the variables.
  // Otherwise, this can be skipped.
  virtual void SetUp() {
    g_ = new Game();
  }

  // virtual void TearDown() will be called after each test is run.
  virtual void TearDown() {
    delete g_;
  }

  // helper functions
  void RollMany(int n, int pins) {
    for (int i = 0; i < n; i++)
      g_->Roll(pins);
  }

  void RollSpare() {
    g_->Roll(5);
    g_->Roll(5);
  }

  void RollStrike() {
    g_->Roll(10);
  }

  // Declares the variables your tests want to use.
  Game* g_;
};


// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>

// 1st Test: Tests gutter game.
TEST_F(BowlingGameTest, GutterGame) {
  // Arrange
  
  // Act
  RollMany(20, 0);

  // Assert 
  EXPECT_EQ(0, g_->Score());
}

// 2nd Test: Tests all ones.
TEST_F(BowlingGameTest, AllOnes) {
  // Arrange
  
  // Act
  RollMany(20, 1);

  // Assert 
  EXPECT_EQ(20, g_->Score());
}

// 3rd Test: Tests one spare.
TEST_F(BowlingGameTest, OneSpare) {
  // Arrange
  
  // Act
  RollSpare();
  g_->Roll(3);
  RollMany(17, 0);

  // Assert 
  EXPECT_EQ(16, g_->Score());
}

// 4th Test: Tests one strike.
TEST_F(BowlingGameTest, OneStrike) {
  // Arrange
  
  // Act
  RollStrike();
  g_->Roll(3);
  g_->Roll(4);
  RollMany(16, 0);

  // Assert 
  EXPECT_EQ(24, g_->Score());
}

// 5th Test: Tests perfect game.
TEST_F(BowlingGameTest, PerfectGame) {
  // Arrange
  
  // Act
  RollMany(12, 10);

  // Assert 
  EXPECT_EQ(300, g_->Score());
}

}  // namespace

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?
