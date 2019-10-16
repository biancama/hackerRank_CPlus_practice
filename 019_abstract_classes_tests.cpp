#include "catch.hpp"
#include "019_abstract_classes.cpp"

TEST_CASE("Abstract classes 01") {
    LRUCache l(5);
    l.set(1, 2);

    int value = l.get(1);
    REQUIRE(value == 2);

    value = l.get(2);
    REQUIRE(value == -1);

}

TEST_CASE("Abstract classes 02") {
    LRUCache l(5);
    l.set(4, 4);
    l.set(1, 1);
    l.set(2, 2);
    l.set(3, 3);
    l.set(5, 5);
    //cout << l.to_string() << endl;

    int value = l.get(4);
    //cout << l.to_string() << endl;
    REQUIRE(value == 4);

    l.set(1, 1);
    value = l.get(4);

    //cout << l.to_string() << endl;
    REQUIRE(value == 4);

    l.set(6, 6);
    value = l.get(2);
    //cout << l.to_string() << endl;
    REQUIRE(value == 2);

}

TEST_CASE("Abstract classes 03") {
    LRUCache l(1);
    int value = l.get(4);
    REQUIRE(value == -1);

    l.set(1, 1);
    value = l.get(1);
    REQUIRE(value == 1);

    l.set(2, 2);
    value = l.get(2);
    REQUIRE(value == 2);
}