// test_dzielenie.cpp
#include <gtest/gtest.h>
#include <cmath> // Dodaj nagłówek dla std::isnan
#include "dzielenie.h"

TEST(DivideTest, NonZeroDenominator) {
    EXPECT_DOUBLE_EQ(2.0, divide(4.0, 2.0));
    EXPECT_DOUBLE_EQ(3.0, divide(9.0, 3.0));
}

TEST(DivideTest, ZeroDenominator) {
    double result = divide(4.0, 0.0);
    EXPECT_TRUE(std::isnan(result)); // Sprawdź, czy wynik jest NaN
}