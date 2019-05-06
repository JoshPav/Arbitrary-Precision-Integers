#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "integer.h"
#include "negativenumbererror.h"
#include "dividebyzeroerror.h"

using namespace ExactArithmetic;

BOOST_AUTO_TEST_SUITE ( ArithmeticTests )

    BOOST_AUTO_TEST_SUITE ( SubtractionTests )

        BOOST_AUTO_TEST_CASE ( SubLongShort )
        {
            Integer A("9134861215415000088880");
            Integer B("5000088880");

            Integer C = A-B;

	        BOOST_CHECK_EQUAL(C,Integer("9134861215410000000000"));
        }

        BOOST_AUTO_TEST_CASE ( SubShortLong )
        {
            Integer A("9134861215415000088880");
            Integer B("5000088880");

            BOOST_CHECK_THROW(B-A, NegativeNumberError);
        }

        BOOST_AUTO_TEST_CASE ( SubShortShort )
        {
            Integer A("785668565325");
            Integer B("561521514514");

            Integer C = A-B;

            BOOST_CHECK_EQUAL(C, Integer("224147050811"));
        }

        BOOST_AUTO_TEST_CASE ( SubLongLong )
        {
            Integer A("4324237498237492927349247892");
            Integer B("3324237498237492927349247892");

            Integer C = A-B;

            BOOST_CHECK_EQUAL(C,Integer("1000000000000000000000000000"));
        }

        BOOST_AUTO_TEST_CASE ( SubCarryOver )
        {
            Integer A("71465398");
            Integer B("62578499");

            Integer C = A-B;

            BOOST_CHECK_EQUAL(C,Integer("8886899"));
        }

        BOOST_AUTO_TEST_CASE ( SubSame )
        {
            Integer A("342467151927642442464");
            Integer B("342467151927642442464");

            Integer C = A-B;

            BOOST_CHECK_EQUAL(C,Integer("0"));
        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE ( AdditionTests )

        BOOST_AUTO_TEST_CASE(addSimplestCase){
            Integer newInt(0);
            Integer newInt2(0);
            Integer newInt3 = newInt + newInt2;

            BOOST_CHECK_EQUAL(newInt3 ,Integer("0"));
        }

        BOOST_AUTO_TEST_CASE(addSimpleCase){
            Integer newInt(1);
            Integer newInt2(2);
            Integer newInt3 = newInt + newInt2;

            BOOST_CHECK_EQUAL(newInt3 ,Integer("3"));
        }

        BOOST_AUTO_TEST_CASE(addFrontAppend){
            Integer newInt(9);
            Integer newInt2(9);
            Integer newInt3 = newInt + newInt2;

            BOOST_CHECK_EQUAL(newInt3 ,Integer("18"));
        }

        BOOST_AUTO_TEST_CASE(addOverflow){
            Integer newInt(13);
            Integer newInt2(7);
            Integer newInt3 = newInt + newInt2;

            BOOST_CHECK_EQUAL(newInt3 ,Integer("20"));
        }

        BOOST_AUTO_TEST_CASE(addMulyipleOVerflow){
            Integer newInt(16849);
            Integer newInt2(7238);
            Integer newInt3 = newInt + newInt2;

            BOOST_CHECK_EQUAL(newInt3 ,Integer("24087"));
        }

        BOOST_AUTO_TEST_CASE(addMulyipleOverflowAndFrontAppend){
            Integer newInt(16849);
            Integer newInt2(97238);
            Integer newInt3 = newInt + newInt2;

            BOOST_CHECK_EQUAL(newInt3 ,Integer("114087"));
        }

        BOOST_AUTO_TEST_CASE(FirstNumLessDigits){
            Integer newInt2(168490);
            Integer newInt(97238);
            Integer newInt3 = newInt + newInt2;

            BOOST_CHECK_EQUAL(newInt3 ,Integer("265728"));
        }

    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE ( MultiplicationTests )

        BOOST_AUTO_TEST_CASE ( TimesZero )
        {
            Integer A("2651561");
            Integer B;

            Integer C = A*B;

            BOOST_CHECK_EQUAL(C,Integer());

        }

        BOOST_AUTO_TEST_CASE ( TimesOne )
        {
            Integer A("2651561");
            Integer B("1");

            Integer C = A*B;

            BOOST_CHECK_EQUAL(C,A);

        }

        BOOST_AUTO_TEST_CASE ( Square )
        {
            Integer A("156156");
            Integer B("156156");

            Integer C = A*B;

            BOOST_CHECK_EQUAL(C,Integer("24384696336"));

        }

        BOOST_AUTO_TEST_CASE ( LotsOfCarry )
        {
            Integer A("99999999999");
            Integer B("3");

            Integer C = A*B;

            BOOST_CHECK_EQUAL(C,Integer("299999999997"));

        }

        BOOST_AUTO_TEST_CASE ( TwoSmall )
        {
            Integer A("190");
            Integer B("200");

            Integer C = A*B;

            BOOST_CHECK_EQUAL(C,Integer("38000"));
        }

        BOOST_AUTO_TEST_CASE ( SmallLarge )
        {
            Integer A("10");
            Integer B("6156163156165");

            Integer C = A*B;

            BOOST_CHECK_EQUAL(C,Integer("61561631561650"));
        }

        BOOST_AUTO_TEST_CASE ( LargeSmall )
        {            
            Integer A("6156163156165");
            Integer B("10");

            Integer C = A*B;

            BOOST_CHECK_EQUAL(C,Integer("61561631561650"));
        }

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

            BOOST_CHECK_EQUAL( C , ExactArithmetic::Integer(2865490));
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
        
    BOOST_AUTO_TEST_SUITE_END()

    BOOST_AUTO_TEST_SUITE ( ModuloTests )

        BOOST_AUTO_TEST_CASE ( ModuloZero ){
            ExactArithmetic::Integer A("3649827349");
            ExactArithmetic::Integer B("0");

            BOOST_CHECK_THROW( A%B , ExactArithmetic::DivideByZeroError);
        }

        BOOST_AUTO_TEST_CASE ( ModuloOne ){
            ExactArithmetic::Integer A("56050151");
            ExactArithmetic::Integer B("1");

            ExactArithmetic::Integer C = A%B;

            BOOST_CHECK_EQUAL( C , Integer("0"));
        }

        BOOST_AUTO_TEST_CASE ( ModuloOdd ){
            ExactArithmetic::Integer A("12237");
            ExactArithmetic::Integer B("2");

            ExactArithmetic::Integer C = A%B;

            BOOST_CHECK_EQUAL( C , Integer("1"));
        }

        BOOST_AUTO_TEST_CASE ( ModuloEven ){
            ExactArithmetic::Integer A("45600");
            ExactArithmetic::Integer B("2");

            ExactArithmetic::Integer C = A%B;

            BOOST_CHECK_EQUAL( C , Integer("0"));
        }

        BOOST_AUTO_TEST_CASE ( RemainerOne ){
            ExactArithmetic::Integer A("45600");
            ExactArithmetic::Integer B("45599");

            ExactArithmetic::Integer C = A%B;

            BOOST_CHECK_EQUAL( C , Integer("1"));
        }

        BOOST_AUTO_TEST_CASE ( BiggerNumber ){
            ExactArithmetic::Integer A("3423");
            ExactArithmetic::Integer B("4000");

            ExactArithmetic::Integer C = A%B;

            BOOST_CHECK_EQUAL( C , Integer("0"));
        }

    BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
