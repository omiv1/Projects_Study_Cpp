// test_main.cpp
#include <gtest/gtest.h>
#include "liczba_pierwsza.h"

TEST(IsPrimeTest, ZeroIsNotPrime) {
    EXPECT_FALSE(isPrime(0));
}

TEST(IsPrimeTest, OneIsNotPrime) {
    EXPECT_FALSE(isPrime(1));
}

TEST(IsPrimeTest, TwoIsPrime) {
    EXPECT_TRUE(isPrime(2));
}

TEST(IsPrimeTest, PrimeNumbers) {
    EXPECT_TRUE(isPrime(3));
    EXPECT_TRUE(isPrime(5));
    EXPECT_TRUE(isPrime(7));
    EXPECT_TRUE(isPrime(11));
    EXPECT_TRUE(isPrime(13));
}

TEST(IsPrimeTest, NonPrimeNumbers) {
    EXPECT_FALSE(isPrime(4));
    EXPECT_FALSE(isPrime(6));
    EXPECT_FALSE(isPrime(8));
    EXPECT_FALSE(isPrime(9));
    EXPECT_FALSE(isPrime(10));
}
