#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "integer.h"
#include "negativenumbererror.h"
#include "dividebyzeroerror.h"

using namespace ExactArithmetic;

BOOST_AUTO_TEST_SUITE ( CompoundOperatorTests )

    BOOST_AUTO_TEST_SUITE ( AdditionTests )

            BOOST_AUTO_TEST_CASE(addSimplestCase){
            Integer newInt(0);
            Integer newInt2(0);
            newInt += newInt2;

            BOOST_CHECK_EQUAL(newInt , Integer());
        }

        BOOST_AUTO_TEST_CASE(addSimpleCase){
            Integer newInt(1);
            Integer newInt2(2);
            newInt += newInt2;

            BOOST_CHECK_EQUAL(newInt , Integer("3"));
        }

        BOOST_AUTO_TEST_CASE(addFrontAppend){
            Integer newInt(9);
            Integer newInt2(9);
            newInt += newInt2;

            BOOST_CHECK_EQUAL(newInt , Integer("18"));
        }

        BOOST_AUTO_TEST_CASE(addOverflow){
            Integer newInt(13);
            Integer newInt2(7);
            newInt += newInt2;

            BOOST_CHECK_EQUAL(newInt , Integer("20"));
        }

        BOOST_AUTO_TEST_CASE(addMulyipleOVerflow){
            Integer newInt(16849);
            Integer newInt2(7238);
            newInt += newInt2;

            BOOST_CHECK_EQUAL(newInt , Integer("24087"));
        }

        BOOST_AUTO_TEST_CASE(addMulyipleOverflowAndFrontAppend){
            Integer newInt(16849);
            Integer newInt2(97238);
            newInt += newInt2;

            BOOST_CHECK_EQUAL(newInt , Integer("114087"));
        }

        BOOST_AUTO_TEST_CASE(FirstNumLessDigits){
            Integer newInt2(168490);
            Integer newInt(97238);
            newInt += newInt2;

            BOOST_CHECK_EQUAL(newInt , Integer("265728"));
        }
    BOOST_AUTO_TEST_SUITE_END ()

    BOOST_AUTO_TEST_SUITE ( SubtractionTests )
        BOOST_AUTO_TEST_CASE ( SubequalLongShort )
        {
            Integer A("9134861215415000088880");
            Integer B("5000088880");

            A -= B;

            BOOST_CHECK_EQUAL(A,Integer("9134861215410000000000"));
        }

        BOOST_AUTO_TEST_CASE ( SubShortShortLong )
        {
            Integer A("9134861215415000088880");
            Integer B("5000088880");

            BOOST_CHECK_THROW(B-=A, NegativeNumberError);
        }

        BOOST_AUTO_TEST_CASE ( SubequalShortShort )
        {
            Integer A("785668565325");
            Integer B("561521514514");

            A -= B;

            BOOST_CHECK_EQUAL(A, Integer("224147050811"));
        }

        BOOST_AUTO_TEST_CASE ( SubequalLongLong )
        {
            Integer A("4324237498237492927349247892");
            Integer B("3324237498237492927349247892");

            A -= B;

            BOOST_CHECK_EQUAL(A,Integer("1000000000000000000000000000"));
        }

        BOOST_AUTO_TEST_CASE ( SubequalCarryOver )
        {
            Integer A("71465398");
            Integer B("62578499");

            A -= B;

            BOOST_CHECK_EQUAL(A,Integer("8886899"));
        }

        BOOST_AUTO_TEST_CASE ( SubequalSame )
        {
            Integer A("342467151927642442464");
            Integer B("342467151927642442464");

            A-=B;

            BOOST_CHECK_EQUAL(A,Integer("0"));
        }

    BOOST_AUTO_TEST_SUITE_END ()

    BOOST_AUTO_TEST_SUITE ( MultiplicationTests )
    BOOST_AUTO_TEST_SUITE_END ()

    BOOST_AUTO_TEST_SUITE ( DivisionTests )

        BOOST_AUTO_TEST_CASE ( CompoundDivideByZero ){
            ExactArithmetic::Integer A("3649827349");
            ExactArithmetic::Integer B("0");

            BOOST_CHECK_THROW( A/=B , ExactArithmetic::DivideByZeroError);
        }

        BOOST_AUTO_TEST_CASE ( CompoundWholeDivideSmall)
        {
            ExactArithmetic::Integer A("450");
            ExactArithmetic::Integer B("25");

            A/=B;

            BOOST_CHECK_EQUAL( A , ExactArithmetic::Integer("18"));
        }

        BOOST_AUTO_TEST_CASE ( CompoundWholeDivideLarge)
        {
            ExactArithmetic::Integer A("286549000000");
            ExactArithmetic::Integer B("100000");
            A/=B;

            BOOST_CHECK_EQUAL( A , ExactArithmetic::Integer(2865490000));
        }

        BOOST_AUTO_TEST_CASE ( CompoundNotDivisible )
        {
            ExactArithmetic::Integer A("32");
            ExactArithmetic::Integer B("150");
            A/=B;

            BOOST_CHECK_EQUAL( A , ExactArithmetic::Integer());
        }

        BOOST_AUTO_TEST_CASE ( CompoundRemainderDivideSmall )
        {
            ExactArithmetic::Integer A("50");
            ExactArithmetic::Integer B("3");
            A/=B;

            BOOST_CHECK_EQUAL( A , ExactArithmetic::Integer(16));
        }
        
        BOOST_AUTO_TEST_CASE ( CompoundRemainderDivideLarge )
        {
            ExactArithmetic::Integer A("2999999999999999");
            ExactArithmetic::Integer B("300000000");

            A/=B;

            BOOST_CHECK_EQUAL( A , ExactArithmetic::Integer("10000000"));
        }

    BOOST_AUTO_TEST_SUITE_END ()

BOOST_AUTO_TEST_SUITE_END()