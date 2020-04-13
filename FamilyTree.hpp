#include <iostream>
using namespace std;

namespace family{
	
	class Tree{
		public : 
		Tree(string nroot);
		Tree addFather(string to,string add);
		Tree addMother(string to,string add);
		string display();
		string relation(string which);
		string find(string who);
		void remove(string who);
	};

}
