//
// Created by Massimo Biancalani on 30/09/2019.
//
#include "catch.hpp"
#include "020_inheritance.h"
#include <sstream>
#include <iostream>
void counterspell(Spell *spell);
TEST_CASE("Inheritance 01") {
    Spell* spell = new Fireball(5);

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    counterspell(spell);

    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss.str() == "Fireball: 5\n");
    std::cout << oss.str();

}
TEST_CASE("Inheritance 02") {
    Spell* spell = new Spell("AquaVitae");
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    SpellJournal::journal = "AruTaVae";

    counterspell(spell);

    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss.str() == "6\n");
    std::cout << oss.str();
}


TEST_CASE("Inheritance 03") {
    Spell* spell = new Spell("ABCABCDE");
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    SpellJournal::journal = "ABCDE";

    counterspell(spell);

    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss.str() == "5\n");
    std::cout << oss.str();
}

TEST_CASE("Inheritance 04") {
    Spell* spell = new Spell("faPkdmElxiyjROOhuFHbaKpmmVAXQcPTiwtCiJC");
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    SpellJournal::journal = "BVObzwbRESpqhpvjiDGmlVJ";

    counterspell(spell);

    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss.str() == "6\n");
    std::cout << oss.str();
}