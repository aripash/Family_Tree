#include "doctest.h"
#include "FamilyTree.hpp"
#include <iostream>
#include <string>

TEST_CASE("testing the test"){
family::Tree T("test");
for(int i = 0; i <101; i++){
	CHECK(T.relation("i").compare("me")==0);
}
}