#include "FamilyTree.hpp"
#include <iostream>
using namespace std;


node :: node(string nname, string nrelation){}
void node :: addM(node nM){}
void node :: addF(node nF){}

namespace family{
	
		Tree :: Tree(string nroot){}
		Tree Tree :: addFather(string to,string add){return *this;}
		Tree Tree :: addMother(string to,string add){return *this;}
		string Tree :: display(){return "";}
		string Tree :: relation(string which){return "me";}
		string Tree :: find(string who){return "";}
		void Tree :: remove(string who){}

}
