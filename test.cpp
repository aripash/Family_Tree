#include "FamilyTree.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

TEST_CASE("currect code"){
	family::Tree T1 ("test");
	CHECK(T1.relation("test").compare("me")==0);
	CHECK(T1.relation("Ftest").compare("unrelated")==0);
	T1.addFather("idk","Ftest");
	CHECK(T1.relation("Ftest").compare("father")==0);
	CHECK_THROWS(family::Tree T2 (5));
	T1.remove("test");
	CHECK(T1.relation("test").compare("unrelated")==0);
	CHECK(T1.relation("Ftest").compare("unrelated")==0);
	
}

TEST_CASE("tree"){
	family::Tree T ("test");
	T.addFather("idk","Ftest");
	T.addMother("idk","Mtest");
	T.addFather("Ftest","FFtest");
	T.addMother("Ftest","MFtest");
	T.addFather("Mtest","FMtest");
	T.addMother("Mtest","MMtest");
	CHECK(T.relation("test").compare("me")==0);
	CHECK(T.relation("Ftest").compare("father")==0);
	CHECK(T.relation("Mtest").compare("mother")==0);
	CHECK(T.relation("FFtest").compare("grandfather")==0);
	CHECK(T.relation("FMtest").compare("grandmother")==0);
	CHECK(T.relation("MFtest").compare("grandfather")==0);
	CHECK(T.relation("MMtest").compare("grandmother")==0);
	CHECK(T.find("me").compare("test")==0);
	CHECK(T.find("father").compare("Ftest")==0);
	CHECK(T.find("mother").compare("Mtest")==0);
	CHECK(T.find("grandfather").compare("FFtest")==0||T.find("grandfather").compare("FMtest")==0);
	CHECK(T.find("grandmother").compare("MMtest")==0||T.find("grandmother").compare("MFtest")==0);
	T.remove("test");
	CHECK(T.relation("test").compare("unrelated")==0);
	CHECK(T.relation("Ftest").compare("unrelated")==0);
	CHECK(T.relation("Mtest").compare("unrelated")==0);
	CHECK(T.relation("FFtest").compare("unrelated")==0);
	CHECK(T.relation("FMtest").compare("unrelated")==0);
	CHECK(T.relation("MFtest").compare("unrelated")==0);
	CHECK(T.relation("MMtest").compare("unrelated")==0);
	CHECK(T.find("me").compare("unrelated")==0);
	CHECK(T.find("father").compare("unrelated")==0);
	CHECK(T.find("mother").compare("unrelated")==0);
	CHECK(T.find("grandfather").compare("unrelated")==0);
	CHECK(T.find("grandmother").compare("unrelated")==0);
}

TEST_CASE("testing the test"){
	family::Tree T ("test");
	for(int i = 0; i <101; i++){
		CHECK(T.relation(to_string(i)).compare("me")==0);	
	}
}

