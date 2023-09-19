#include <gtest/gtest.h>
#include <string>
#include "lib.h"

TEST(ExampleTest, BasicAsExasertions) {
   // arrange
   std::string a{"2"}, b{"7"}, err{""};
   long long int res;

   // act
   res = lab0(a, b);
   if (res < 0) err = check_error(res);

   // assert
   EXPECT_EQ(res, 11);
   EXPECT_EQ(err, "");
}

TEST(NegativeErrTest_a, BasicAsExasertions) {
   // arrange
   std::string a{"-3"}, b{"7"}, err{""};
   long long int res;

   // act
   res = lab0(a, b);
   if (res < 0) err = check_error(res);

   // assert
   EXPECT_EQ(res, -1);
   EXPECT_EQ(err, "Number must be unsignused");
}

TEST(NegativeErrTest_b, BasicAsExasertions) {
   // arrange
   std::string a{"3"}, b{"-7"}, err{""};
   long long int res;

   // act
   res = lab0(a, b);
   if (res < 0) err = check_error(res);

   // assert
   EXPECT_EQ(res, -1);
   EXPECT_EQ(err, "Number must be unsignused");
}

TEST(CompareErrTest, BasicAsExasertions) {
   // arrange
   std::string a{"8"}, b{"7"}, err{""};
   long long int res;

   // act
   res = lab0(a, b);
   if (res < 0) err = check_error(res);

   // assert
   EXPECT_EQ(res, -2);
   EXPECT_EQ(err, "Number \"b\" must be more than number \"a\"");
}

TEST(InputStringErrTest_a, BasicAsExasertions) {
   // arrange
   std::string a{"a"}, b{"7"}, err{""};
   long long int res;

   // act
   res = lab0(a, b);
   if (res < 0) err = check_error(res);

   // assert
   EXPECT_EQ(res, -3);
   EXPECT_EQ(err, "Please, input number, not string");
}

TEST(InputStringErrTest_b, BasicAsExasertions) {
   // arrange
   std::string a{"2"}, b{"a"}, err{""};
   long long int res;

   // act
   res = lab0(a, b);
   if (res < 0) err = check_error(res);

   // assert
   EXPECT_EQ(res, -3);
   EXPECT_EQ(err, "Please, input number, not string");
}

TEST(Func__check_error__Test, BasicAsExasertions) {
   // arrange

   // act

   // assert
   EXPECT_EQ(check_error(1), "");
   EXPECT_EQ(check_error(0), "");
   EXPECT_EQ(check_error(-1), "Number must be unsignused");
   EXPECT_EQ(check_error(-2), "Number \"b\" must be more than number \"a\"");
   EXPECT_EQ(check_error(-3), "Please, input number, not string");
   EXPECT_EQ(check_error(-4), "");
}

TEST(Func__check_num__Test, BasicAsExasertions) {
   // arrange

   // act

   // assert
   EXPECT_EQ(check_num("0"), 0);
   EXPECT_EQ(check_num("1"), 1);
   EXPECT_EQ(check_num("-1"), -1);
   EXPECT_EQ(check_num("-2"), -1);
   EXPECT_EQ(check_num("-3"), -1);
   EXPECT_EQ(check_num("fle"), -3);
   EXPECT_EQ(check_num(""), -3);
   EXPECT_EQ(check_num("100"), 100);
}

TEST(Func__compare_nums__Test, BasicAsExasertions) {
   // arrange

   // act

   // assert
   EXPECT_EQ(compare_nums(1, 1), false);
   EXPECT_EQ(compare_nums(2, 1), false);
   EXPECT_EQ(compare_nums(1, 2), true);
}

TEST(Func__bin__Test, BasicAsExasertions) {
   // arrange

   // act

   // assert
   EXPECT_EQ(bin(0), 0);
   EXPECT_EQ(bin(1), 1);
   EXPECT_EQ(bin(2), 10);
   EXPECT_EQ(bin(100), 1100100);
}

TEST(Func__count__Test, BasicAsExasertions) {
   // arrange

   // act

   // assert
   EXPECT_EQ(count(0), 0);
   EXPECT_EQ(count(1), 1);
   EXPECT_EQ(count(111010), 4);
   EXPECT_EQ(count(10001), 2);
   EXPECT_EQ(count(100000), 1);
}

TEST(Func__sum_bin__Test, BasicAsExasertions) {
   // arrange

   // act

   // assert
   EXPECT_EQ(sum_bin(2, 7), 11);
   EXPECT_EQ(sum_bin(0, 1), 1);
   EXPECT_EQ(sum_bin(10, 11), 5);
}