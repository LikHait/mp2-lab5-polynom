#include <gtest.h>
#include "polinom.h"

int TPolinom::p;

TEST(TPolinom, can_create_polinom)
{
    TPolinom::setP(10);
    ASSERT_NO_THROW(TPolinom polin());
}

TEST(TPolinom, can_create_not_empty_polinom)
{
	string str = "x^2";
	ASSERT_NO_THROW(TPolinom polin(str));
}

TEST(TPolinom, can_convert_empty_polinom_to_string)
{
    TPolinom polin;
    string strRes = "0";
    EXPECT_EQ(strRes, polin.ToString());
}

TEST(TPolinom, can_convert_polinom_to_string)
{
    string str = "16.000000y^1";
    TPolinom polin(str);
    string strRes = polin.ToString();
    EXPECT_EQ(str, strRes);
}

TEST(TPolinom, can_add_two_polinom_with_different_degrees)
{
    string str = "16.000000y^1";
    string str2 = "23.000000z^4";
    TPolinom polin(str);
    TPolinom polin2(str2);
    string strRes = "16.000000y^1+23.000000z^4";
    EXPECT_EQ(strRes, (polin + polin2).ToString());
}

TEST(TPolinom, can_add_two_polinom_with_equal_degrees)
{
    string str = "16.000000z^4";
    string str2 = "23.000000z^4";
    TPolinom polin(str);
    TPolinom polin2(str2);
    string strRes = "39.000000z^4";
    EXPECT_EQ(strRes, (polin + polin2).ToString());
}

TEST(TPolinom, can_deduct_two_polinom_with_different_degrees)
{
    string str = "16.000000x^7y^4+19.000000z^3";
    string str2 = "23.000000z^4";
    TPolinom polin(str);
    TPolinom polin2(str2);
    string strRes = "16.000000x^7y^4-23.000000z^4+19.000000z^3";
    EXPECT_EQ(strRes, (polin - polin2).ToString());
}

TEST(TPolinom, can_deduct_two_polinom_with_equal_degrees)
{
    string str = "16.000000x^7y^4+19.000000z^3";
    string str2 = "19.000000x^7y^4+19.000000z^3";
    TPolinom polin(str);
    TPolinom polin2(str2);
    string strRes = "-3.000000x^7y^4";
    EXPECT_EQ(strRes, (polin - polin2).ToString());
}

TEST(TPolinom, can_multiply_polinom_by_number)
{
    string str = "16.000000x^7y^4+19.000000z^3";
    double num = 4.6;
    TPolinom polin(str);
    string strRes = "73.600000x^7y^4+87.400000z^3";
    EXPECT_EQ(strRes, (polin * num).ToString());
}

TEST(TPolinom, can_multiply_polinom_by_positive_number)
{
    string str = "16.000000x^7y^4+19.000000z^3";
    double num = 4.6;
    TPolinom polin(str);
    string strRes = "73.600000x^7y^4+87.400000z^3";
    EXPECT_EQ(strRes, (polin * num).ToString());
}

TEST(TPolinom, can_multiply_polinom_by_negative_number)
{
    string str = "16.000000x^7y^4+19.000000z^3";
    double num = -4.6;
    TPolinom polin(str);
    string strRes = "-73.600000x^7y^4-87.400000z^3";
    EXPECT_EQ(strRes, (polin * num).ToString());
}

TEST(TPolinom, can_be_calculated_with_given_values)
{
	string str = "16x^7y^4+19z^3";
	double x = 7;
    double y = 1.2;
    double z = 3;
    TPolinom polin(str);
    double Res = 16 * pow(x, 7) * pow(y, 4) + 19 * pow(z, 3);
	double calcRes = polin.Calculate(x, y, z);
    EXPECT_EQ(abs(Res - calcRes) < 0.001, 1);
}
