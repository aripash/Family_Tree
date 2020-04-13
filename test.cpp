#include "FamilyTree.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

/*TEST_CASE("testing the test"){
	family::Tree T ("test");
	for(int i = 0; i <101; i++){
		CHECK(T.relation(to_string(i)).compare("me")==0);	
	}
}*/

TEST_CASE("idk"){
	family::Tree T ("idk");
	CHECK(T.relation("idk").compare("unrelated")==0);
	CHECK(T.relation("id").compare("unrelated")==0);
}