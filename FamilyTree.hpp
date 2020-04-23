#include <iostream>
using namespace std;




namespace family{
	
	class Tree{
		public : 
		string _name;
		Tree* _m;
		Tree* _f;
		int _depth;
		Tree(string name);
		Tree(string name,int depth);
		Tree(){
			_name="";
			_m=nullptr;
			_f=nullptr;
		}
		Tree* search(string who);
		void change(string name,int depth);
		Tree& addFather(string to,string add);
		Tree& addMother(string to,string add);
		string display();
		string relation(string which);
		string find(string who);
		void remove(string who);
	};

}
