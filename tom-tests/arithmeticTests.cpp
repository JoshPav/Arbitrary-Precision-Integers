#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "integer.h"
#include <stdexcept>

using namespace ExactArithmetic;


BOOST_AUTO_TEST_SUITE(arithmeticTests)

  BOOST_AUTO_TEST_SUITE(additionTests)

    BOOST_AUTO_TEST_CASE(addSimplestCase){
      Integer newInt(0);
      Integer newInt2(0);
      Integer newInt3 = newInt + newInt2;

      BOOST_CHECK_EQUAL(newInt3.toString() , "0");
    }

    BOOST_AUTO_TEST_CASE(addSimpleCase){
      Integer newInt(1);
      Integer newInt2(2);
      Integer newInt3 = newInt + newInt2;

      BOOST_CHECK_EQUAL(newInt3.toString() , "3");
    }

    BOOST_AUTO_TEST_CASE(addFrontAppend){
      Integer newInt(9);
      Integer newInt2(9);
      Integer newInt3 = newInt + newInt2;

      BOOST_CHECK_EQUAL(newInt3.toString() , "18");
    }

    BOOST_AUTO_TEST_CASE(addOverflow){
      Integer newInt(13);
      Integer newInt2(7);
      Integer newInt3 = newInt + newInt2;

      BOOST_CHECK_EQUAL(newInt3.toString() , "20");
    }

    BOOST_AUTO_TEST_CASE(addMulyipleOVerflow){
      Integer newInt(16849);
      Integer newInt2(7238);
      Integer newInt3 = newInt + newInt2;

      BOOST_CHECK_EQUAL(newInt3.toString() , "24087");
    }

    BOOST_AUTO_TEST_CASE(addMulyipleOverflowAndFrontAppend){
      Integer newInt(16849);
      Integer newInt2(97238);
      Integer newInt3 = newInt + newInt2;

      BOOST_CHECK_EQUAL(newInt3.toString() , "114087");
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(subtractionTests)
  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(multiplicationTests)

    BOOST_AUTO_TEST_CASE ( ZeroTimesZero )
    {
      Integer A("0");
      Integer B("0");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("0") );
    }

   BOOST_AUTO_TEST_CASE ( ZeroTimesA )
    {
      Integer A("2423423428");
      Integer B("0");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("0") );
    }

   BOOST_AUTO_TEST_CASE ( OneDigitLessThan10 )
    {
      Integer A("3");
      Integer B("2");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("6") );
    }

   BOOST_AUTO_TEST_CASE ( OneOverflowTest )
    {
      Integer A("2");
      Integer B("5");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("10") );
    }

   BOOST_AUTO_TEST_CASE ( TwoDigitOneDigit )
    {
      Integer A("11");
      Integer B("6");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("66") );
    }

    BOOST_AUTO_TEST_CASE ( TwoDigitTwoDigit )
    {
      Integer A("11");
      Integer B("12");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("132") );
    }

    BOOST_AUTO_TEST_CASE ( ThreeDigitOneDigit )
    {
      Integer A("104");
      Integer B("2");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("208") );
    }

    BOOST_AUTO_TEST_CASE ( ThreeDigitThreeDigit )
    {
      Integer A("101");
      Integer B("301");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("30401") );
    }

    BOOST_AUTO_TEST_CASE ( LotsOfZeros )
    {
      Integer A("10000000000000000");
      Integer B("90000000000990000");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("900000000009900000000000000000000") );
    }


    BOOST_AUTO_TEST_CASE ( LotsOfCarry )
    {
      Integer A("9999999");
      Integer B("3");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("29999997") );
    }

    BOOST_AUTO_TEST_CASE ( TwoBigNumbers )
    {
      Integer A("99999999");
      Integer B("20000002");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("2000000179999998") );
    }

    BOOST_AUTO_TEST_CASE ( DataTypeLimitTest )
    {
      Integer A("18446744073709551616");
      Integer B("1");

      Integer C = A*B;

      BOOST_CHECK_EQUAL ( C , Integer("18446744073709551616") );
    }

  BOOST_AUTO_TEST_SUITE_END()

  BOOST_AUTO_TEST_SUITE(divisionTests)
  BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
