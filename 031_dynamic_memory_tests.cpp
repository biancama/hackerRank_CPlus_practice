//
// Created by Massimo Biancalani on 08/10/2019.
//

#include "catch.hpp"
#include "031_dynamic_memory.h"

TEST_CASE("Dynamic memory 01") {
    int start_times[] = {1, 3, 0, 5, 5, 8};
    int durations[] = {1, 1, 6, 2, 4, 1};
    Available_Workshops* availableWorkshops = initialize(start_times, durations, 6);
    int maxWorkshop = CalculateMaxWorkshops(availableWorkshops);

    REQUIRE(maxWorkshop == 4);
}


TEST_CASE("Dynamic memory 02") {
    int start_times[] = {1, 3, 0, 5, 5, 8, 5};
    int durations[] = {1, 1, 6, 2, 4, 1, 0};
    Available_Workshops* availableWorkshops = initialize(start_times, durations, 7);
    int maxWorkshop = CalculateMaxWorkshops(availableWorkshops);

    REQUIRE(maxWorkshop == 5);
}


TEST_CASE("Dynamic memory 03") {
    int start_times[] = {58, 32, 100, 15, 31, 48, 90, 81, 74, 23, 2, 15, 62};
    int durations[] = {4, 10, 7, 2, 4, 2, 4, 8, 10, 3, 10, 2, 1};
    Available_Workshops* availableWorkshops = initialize(start_times, durations, 13);
    int maxWorkshop = CalculateMaxWorkshops(availableWorkshops);

    REQUIRE(maxWorkshop == 10);
}