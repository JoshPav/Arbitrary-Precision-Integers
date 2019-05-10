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

    BOOST_AUTO_TEST_SUITE(MultiplicationTests)

        BOOST_AUTO_TEST_CASE ( ZeroTimesZero )
        {
            Integer A("0");
            Integer B("0");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("0") );
        }

        BOOST_AUTO_TEST_CASE ( ZeroTimesA )
        {
            Integer A("2423423428");
            Integer B("0");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("0") );
        }

        BOOST_AUTO_TEST_CASE ( OneDigitLessThan10 )
        {
            Integer A("3");
            Integer B("2");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("6") );
        }

        BOOST_AUTO_TEST_CASE ( OneOverflowTest )
        {
            Integer A("2");
            Integer B("5");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("10") );
        }

        BOOST_AUTO_TEST_CASE ( TwoDigitOneDigit )
        {
            Integer A("11");
            Integer B("6");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("66") );
        }

        BOOST_AUTO_TEST_CASE ( TwoDigitTwoDigit )
        {
            Integer A("11");
            Integer B("12");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("132") );
        }

        BOOST_AUTO_TEST_CASE ( ThreeDigitOneDigit )
        {
            Integer A("104");
            Integer B("2");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("208") );
        }

        BOOST_AUTO_TEST_CASE ( ThreeDigitThreeDigit )
        {
            Integer A("101");
            Integer B("301");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("30401") );
        }

        BOOST_AUTO_TEST_CASE ( LotsOfZeros )
        {
            Integer A("10000000000000000");
            Integer B("90000000000990000");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("900000000009900000000000000000000") );
        }

        BOOST_AUTO_TEST_CASE ( LotsOfCarry )
        {
            Integer A("9999999");
            Integer B("3");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("29999997") );
        }

        BOOST_AUTO_TEST_CASE ( TwoBigNumbers )
        {
            Integer A("99999999");
            Integer B("20000002");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("2000000179999998") );
        }

        BOOST_AUTO_TEST_CASE ( DataTypeLimitTest )
        {
            Integer A("18446744073709551616");
            Integer B("1");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("18446744073709551616") );
        }

        BOOST_AUTO_TEST_CASE ( VeryBig )
        {
            Integer A("8000000000000000");
            Integer B("5000000000000000");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("40000000000000000000000000000000") );
        }

        BOOST_AUTO_TEST_CASE ( BigCarryBits )
        {
            Integer A("298747");
            Integer B("68791");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("20551104877") );
        }
        BOOST_AUTO_TEST_CASE ( SmallBig )
        {
            Integer A("67");
            Integer B("17869");

            A*=B;

            BOOST_CHECK_EQUAL ( A , Integer("1197223") );
        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE ( DivisionTests )

        BOOST_AUTO_TEST_CASE ( CompoundDivideByZero ){
            Integer A("3649827349");
            Integer B("0");

            BOOST_CHECK_THROW( A/=B , DivideByZeroError);
        }

        BOOST_AUTO_TEST_CASE ( CompoundWholeDivideSmall)
        {
            Integer A("450");
            Integer B("25");

            A/=B;

            BOOST_CHECK_EQUAL( A , Integer("18"));
        }

        BOOST_AUTO_TEST_CASE ( CompoundWholeDivideLarge)
        {
            Integer A("286549000000");
            Integer B("100000");
            A/=B;

            BOOST_CHECK_EQUAL( A , Integer(2865490));
        }

        BOOST_AUTO_TEST_CASE ( CompoundNotDivisible )
        {
            Integer A("32");
            Integer B("150");
            A/=B;

            BOOST_CHECK_EQUAL( A , Integer());
        }

        BOOST_AUTO_TEST_CASE ( CompoundRemainderDivideSmall )
        {
            Integer A("50");
            Integer B("3");
            A/=B;

            BOOST_CHECK_EQUAL( A , Integer(16));
        }
        
        BOOST_AUTO_TEST_CASE ( CompoundRemainderDivideLarge )
        {
            Integer A("2999999999999999");
            Integer B("300000000");

            A/=B;

            BOOST_CHECK_EQUAL( A , Integer("10000000"));
        }

    BOOST_AUTO_TEST_SUITE_END ()

    BOOST_AUTO_TEST_SUITE ( ModuloTests )

        BOOST_AUTO_TEST_CASE ( ModuloZero ){
            Integer A("3649827349");
            Integer B("0");

            BOOST_CHECK_THROW( A%=B , DivideByZeroError);
        }

        BOOST_AUTO_TEST_CASE ( ModuloOne ){
            Integer A("56050151");
            Integer B("1");

            A%=B;

            BOOST_CHECK_EQUAL( A , Integer("0"));
        }

        BOOST_AUTO_TEST_CASE ( ModuloOdd ){
            Integer A("12237");
            Integer B("2");

            A%=B;

            BOOST_CHECK_EQUAL( A, Integer("1"));
        }

        BOOST_AUTO_TEST_CASE ( ModuloEven ){
            Integer A("45600");
            Integer B("2");

            A%=B;

            BOOST_CHECK_EQUAL( A , Integer("0"));
        }

        BOOST_AUTO_TEST_CASE ( RemainerOne ){
            Integer A("45600");
            Integer B("45599");

            A%=B;

            BOOST_CHECK_EQUAL( A , Integer("1"));
        }

        BOOST_AUTO_TEST_CASE ( BiggerNumber ){
            Integer A("3423");
            Integer B("4000");

            A%=B;

            BOOST_CHECK_EQUAL( A , Integer("0"));
        }

    BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()