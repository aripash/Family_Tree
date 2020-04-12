#include <iostream>
using namespace std;

class node{
	string name;
	string relation;
	node * M;
	node * F;
	public : node(string nname, string nrelation);
	void addM(node nM);
	void addF(node nF);
};
namespace family{
	
	class Tree{
		node * root;
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
