#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "integer.h"
#include "negativenumbererror.h"
#include "dividebyzeroerror.h"

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

    BOOST_AUTO_TEST_SUITE ( AdditionTests )
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE ( MultiplicationTests )
    BOOST_AUTO_TEST_SUITE_END()
    
    BOOST_AUTO_TEST_SUITE ( DivisionTests )

        BOOST_AUTO_TEST_CASE ( DivideByZero ){
            ExactArithmetic::Integer A("3649827349");
            ExactArithmetic::Integer B("0");

            BOOST_CHECK_THROW( A/B , ExactArithmetic::DivideByZeroError);
        }

        BOOST_AUTO_TEST_CASE ( WholeDivideSmall)
        {
            ExactArithmetic::Integer A("450");
            ExactArithmetic::Integer B("25");

            ExactArithmetic::Integer C = A/B;

            BOOST_CHECK_EQUAL( C , ExactArithmetic::Integer("18"));
        }

        BOOST_AUTO_TEST_CASE ( WholeDivideLarge)
        {
            ExactArithmetic::Integer A("286549000000");
            ExactArithmetic::Integer B("100000");
            ExactArithmetic::Integer C = A/B;

            BOOST_CHECK_EQUAL( C , ExactArithmetic::Integer(2865490000));
        }

        BOOST_AUTO_TEST_CASE ( NotDivisible )
        {
            ExactArithmetic::Integer A("32");
            ExactArithmetic::Integer B("150");
            ExactArithmetic::Integer C = A/B;

            BOOST_CHECK_EQUAL( C , ExactArithmetic::Integer());
        }

        BOOST_AUTO_TEST_CASE ( RemainderDivideSmall )
        {
            ExactArithmetic::Integer A("50");
            ExactArithmetic::Integer B("3");
            ExactArithmetic::Integer C = A/B;

            BOOST_CHECK_EQUAL( C , ExactArithmetic::Integer(16));
        }

        BOOST_AUTO_TEST_CASE ( RemainderDivideLarge )
        {
            ExactArithmetic::Integer A("2999999999999999");
            ExactArithmetic::Integer B("300000000");

            ExactArithmetic::Integer C = A/B;

            BOOST_CHECK_EQUAL( C , ExactArithmetic::Integer("10000000"));
        }

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
        
    BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
