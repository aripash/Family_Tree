#include "FamilyTree.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

TEST_CASE("testing the test"){
	family::Tree T ("test");
	for(int i = 0; i <101; i++){
	CHECK(T.relation(to_string(i)).compare("me")==0);	
	}
}

TEST_CASE("idk"){
	family::Tree T ("idk");
	CHECK_THROWS(T.addMother("",""));
}