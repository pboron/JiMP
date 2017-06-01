//
// Created by Student on 01.06.2017.
//

#include <gtest/gtest.h>
#include "ArabicToRoman.h"

class ArabicToRomanTest: public ::testing::Test{
public:

};

TEST_F(ArabicToRomanTest, Roman_Of_2783) {
    EXPECT_EQ("MMDCCLXXXIII", ArabicToRoman(2783));
}

TEST_F(ArabicToRomanTest, Roman_Of_Negative) {
    EXPECT_EQ("ERROR", ArabicToRoman(-142));
}

TEST_F(ArabicToRomanTest, Roman_Of_146) {
    EXPECT_EQ("CXLVI", ArabicToRoman(146));
}

TEST_F(ArabicToRomanTest, Roman_Of_1949) {
    EXPECT_EQ("MCMXLIX", ArabicToRoman(1949));
}

TEST_F(ArabicToRomanTest, Roman_Of_1) {
    EXPECT_EQ("I", ArabicToRoman(1));
}