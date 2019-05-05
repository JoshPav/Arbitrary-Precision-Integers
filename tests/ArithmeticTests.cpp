#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "integer.h"
#include "negativenumbererror.h"

BOOST_AUTO_TEST_SUITE ( ArithmeticTests )
        
    BOOST_AUTO_TEST_SUITE ( SubtractionTests )

        BOOST_AUTO_TEST_CASE ( SubLongShort )
        {
            ExactArithmetic::Integer A("9134861215415000088880");
            ExactArithmetic::Integer B("5000088880");

            ExactArithmetic::Integer C = A-B;
            BOOST_CHECK_EQUAL(C,ExactArithmetic::Integer("9134861215410000000000"));
        }

        BOOST_AUTO_TEST_CASE ( SubShortLong )
        {
            ExactArithmetic::Integer A("9134861215415000088880");
            ExactArithmetic::Integer B("5000088880");

            BOOST_CHECK_THROW(B-A, ExactArithmetic::NegativeNumberError);
        }

        BOOST_AUTO_TEST_CASE ( SubShortShort )
        {
            ExactArithmetic::Integer A("785668565325");
            ExactArithmetic::Integer B("561521514514");

            ExactArithmetic::Integer C = A-B;

            BOOST_CHECK_EQUAL(C, ExactArithmetic::Integer("224147050811"));
        }

        BOOST_AUTO_TEST_CASE ( SubLongLong )
        {
            ExactArithmetic::Integer A("4324237498237492927349247892");
            ExactArithmetic::Integer B("3324237498237492927349247892");

            ExactArithmetic::Integer C = A-B;

            BOOST_CHECK_EQUAL(C,ExactArithmetic::Integer("1000000000000000000000000000"));
        }

        BOOST_AUTO_TEST_CASE ( SubCarryOver )
        {
            ExactArithmetic::Integer A("71465398");
            ExactArithmetic::Integer B("62578499");

            ExactArithmetic::Integer C = A-B;

            BOOST_CHECK_EQUAL(C,ExactArithmetic::Integer("8886899"));
        }

        BOOST_AUTO_TEST_CASE ( SubSame )
        {
            ExactArithmetic::Integer A("342467151927642442464");
            ExactArithmetic::Integer B("342467151927642442464");

            ExactArithmetic::Integer C = A-B;

            BOOST_CHECK_EQUAL(C,ExactArithmetic::Integer("0"));
        }

        BOOST_AUTO_TEST_CASE ( SubequalLongShort )
        {
            ExactArithmetic::Integer A("9134861215415000088880");
            ExactArithmetic::Integer B("5000088880");

            A -= B;

            BOOST_CHECK_EQUAL(A,ExactArithmetic::Integer("9134861215410000000000"));
        }

        BOOST_AUTO_TEST_CASE ( SubShortShortLong )
        {
            ExactArithmetic::Integer A("9134861215415000088880");
            ExactArithmetic::Integer B("5000088880");

            BOOST_CHECK_THROW(B-=A, ExactArithmetic::NegativeNumberError);
        }

        BOOST_AUTO_TEST_CASE ( SubequalShortShort )
        {
            ExactArithmetic::Integer A("785668565325");
            ExactArithmetic::Integer B("561521514514");

            A -= B;

            BOOST_CHECK_EQUAL(A, ExactArithmetic::Integer("224147050811"));
        }

        BOOST_AUTO_TEST_CASE ( SubequalLongLong )
        {
            ExactArithmetic::Integer A("4324237498237492927349247892");
            ExactArithmetic::Integer B("3324237498237492927349247892");

            A -= B;

            BOOST_CHECK_EQUAL(A,ExactArithmetic::Integer("1000000000000000000000000000"));
        }

        BOOST_AUTO_TEST_CASE ( SubequalCarryOver )
        {
            ExactArithmetic::Integer A("71465398");
            ExactArithmetic::Integer B("62578499");

            A -= B;

            BOOST_CHECK_EQUAL(A,ExactArithmetic::Integer("8886899"));
        }

        BOOST_AUTO_TEST_CASE ( SubequalSame )
        {
            ExactArithmetic::Integer A("342467151927642442464");
            ExactArithmetic::Integer B("342467151927642442464");

            A-=B;

            BOOST_CHECK_EQUAL(A,ExactArithmetic::Integer("0"));
        }

    BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()