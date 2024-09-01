// test_pierwiastkowanie.cpp
#include <gtest/gtest.h>
#include "pierwiastek.h"

TEST(SquareRootTest, PositiveNumbers) {
    EXPECT_DOUBLE_EQ(2.0, squareRoot(4.0));
    EXPECT_DOUBLE_EQ(3.0, squareRoot(9.0));
}

TEST(SquareRootTest, Zero) {
    EXPECT_DOUBLE_EQ(0.0, squareRoot(0.0));
}

TEST(SquareRootTest, NegativeNumbers) {
    double result = squareRoot(-1.0);
    EXPECT_TRUE(std::isnan(result)); // Sprawdź, czy wynik jest NaN
}
