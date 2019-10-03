//
// Created by Massimo Biancalani on 02/10/2019.
//
#include "catch.hpp"
#include <iostream>
#include <sstream>
void printKMax(int arr[], int n, int k);
TEST_CASE("Deque 01") {
    int arr[] = {3, 4, 6, 3, 4};

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    printKMax(arr, 5, 2);
    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...

    REQUIRE(oss.str() == "4 6 6 4\n");
    std::cout << oss.str();
}


TEST_CASE("Deque 02") {
    int arr[] = {3, 4, 5, 8, 1, 4, 10};

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    printKMax(arr, 7, 4);
    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...

    REQUIRE(oss.str() == "8 8 8 10\n");
    std::cout << oss.str();
}

TEST_CASE("Deque 03") {
    int arr[] = {3, 4};

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    printKMax(arr, 2, 2);
    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...

    REQUIRE(oss.str() == "4\n");
    std::cout << oss.str();
}

TEST_CASE("Deque 04") {
    int arr[] = {1, 2, 3, 4, 5, 6};

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    printKMax(arr, 6, 2);
    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...

    REQUIRE(oss.str() == "2 3 4 5 6\n");
    std::cout << oss.str();
}

TEST_CASE("Deque 05") {
    int arr[] = {3, 4, 6, 5, 1, 1, 3};

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    printKMax(arr, 7, 2);
    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...

    REQUIRE(oss.str() == "4 6 6 5 1 3\n");
    std::cout << oss.str();
}

TEST_CASE("Deque 06") {
    int arr[] = {3, 4, 6, 5, 1, 1, 3};

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    printKMax(arr, 7, 3);
    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...

    REQUIRE(oss.str() == "6 6 6 5 3\n");
    std::cout << oss.str();
}