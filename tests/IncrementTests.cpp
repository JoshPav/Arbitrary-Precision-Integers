#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "integer.h"
#include "negativenumbererror.h"

using namespace ExactArithmetic;

BOOST_AUTO_TEST_SUITE ( IncrementTests)

    BOOST_AUTO_TEST_CASE ( PostIncrementCheckIncrement )
    {
        Integer I("462394910834");

        I++;

        BOOST_CHECK_EQUAL(I.toString(),"462394910835");
    }

    BOOST_AUTO_TEST_CASE ( PostIncrementCheckPost )
    {
        Integer I("1234");

        BOOST_CHECK_EQUAL((I++).toString(),"1234");
    }

    BOOST_AUTO_TEST_CASE ( PostIncrementCheckCarry )
    {
        Integer I("745999999999999999999");
        I++;
        BOOST_CHECK_EQUAL(I.toString(),"746000000000000000000");
    }

    BOOST_AUTO_TEST_CASE ( PostIncrementCheckAddDigit )
    {
        Integer I("999");
        I++;
        BOOST_CHECK_EQUAL(I.toString(),"1000");
    }

    BOOST_AUTO_TEST_CASE ( PreIncrementCheckIncrement )
    {
        Integer I("342432256");
        ++I;
        BOOST_CHECK_EQUAL(I.toString(),"342432257");
    }

    BOOST_AUTO_TEST_CASE ( PreIncrementCheckPre )
    {
        Integer I("13262621652");

        BOOST_CHECK_EQUAL((++I).toString(),"13262621653");
    }

    BOOST_AUTO_TEST_CASE ( PreIncrementCheckCarry )
    {
        Integer I("621515699999999999");
        ++I;
        BOOST_CHECK_EQUAL(I.toString(),"621515700000000000");
    }

    BOOST_AUTO_TEST_CASE ( PreIncrementCheckAddDigit )
    {
        Integer I("999");
        ++I;
        BOOST_CHECK_EQUAL(I.toString(),"1000");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementCheckDecrement )
    {
        Integer I("615614541");

        I--;

        BOOST_CHECK_EQUAL(I.toString(),"615614540");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementCheckPost )
    {
        Integer I("1234");

        BOOST_CHECK_EQUAL((I--).toString(),"1234");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementCheckCarry )
    {
        Integer I("746000000000000000000");
        I--;
        BOOST_CHECK_EQUAL(I.toString(),"745999999999999999999");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementCheckRemoveDigit )
    {
        Integer I("1000");
        I--;
        BOOST_CHECK_EQUAL(I.toString(),"999");
    }

    BOOST_AUTO_TEST_CASE ( PostDecrementZeroCheck)
    {
        Integer I("0");
        BOOST_CHECK_THROW (I-- , NegativeNumberError);
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementCheckDecrement )
    {
        Integer I("342432256");
        --I;
        BOOST_CHECK_EQUAL(I.toString(),"342432255");
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementCheckPre )
    {
        Integer I("13262621652");

        BOOST_CHECK_EQUAL((--I).toString(),"13262621651");
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementCheckCarry )
    {
        Integer I("621515700000000000");
        --I;
        BOOST_CHECK_EQUAL(I.toString(),"621515699999999999");
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementCheckRemoveDigit )
    {
        Integer I("1000");
        --I;
        BOOST_CHECK_EQUAL(I.toString(),"999");
    }

    BOOST_AUTO_TEST_CASE ( PreDecrementZeroCheck)
    {
        Integer I("0");
        BOOST_CHECK_THROW (--I , NegativeNumberError);
    }

BOOST_AUTO_TEST_SUITE_END()