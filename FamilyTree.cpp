#include "FamilyTree.hpp"
#include <iostream>
#include <stdexcept>
#include <queue> 
using namespace std;
using namespace family;

int depthlength(int depth){
	int out=0;
	while(depth!=0){
		depth/=10;
		out++;
	}
	return out;
}

Tree :: Tree(string name){
	_name=name;
	_m=NULL;
	_f=NULL;
	_depth=0;
}
Tree :: Tree(string name,int depth){
	_name=name;
	_m=NULL;
	_f=NULL;
	_depth=depth;
}
Tree& Tree :: addFather(string to,string add){
	Tree* temp=search(to);
	temp->_f=new Tree(add,temp->_depth*10+2);
	return *this;
}
Tree& Tree :: addMother(string to,string add){
	Tree* temp=search(to);
	temp->_m=new Tree(add,temp->_depth*10+1);
	return *this;
}
string Tree :: display(){
	string out=_name+"\n";
	queue <Tree*> bst;
	bst.push(_m);
	bst.push(_f);
	int depth=1;
	while(!bst.empty()){
		Tree* temp=bst.front();
		bst.pop();
		if(depthlength(temp->_depth)==depth)out+=temp->_name+" ";
		else {
			out+="\n"+temp->_name+" ";
			depth++;
		}
		bst.push(temp->_m);
		bst.push(temp->_f);
	}
	return out;
}
string Tree :: relation(string who){
	int d=search(who)->_depth;
	if(d==0)return "me";
	string out="";
	if(d%10==1)out+="mother";
	else out+="father";
	for(int i=0;i<depthlength(d)-1;i++){
		out="grand-"+out;
	}
	return out;
	
}
string Tree :: find(string which){
	if(which.compare("me")==0)return _name;
	if(which.compare("father")==0)return _f->_name;
	if(which.compare("mother")==0)return _m->_name;
	return "";
}
void Tree :: remove(string who){
	if(who.compare(_name))throw invalid_argument("cant delete root");
}
Tree* Tree :: search(string who){
	if(who.compare(_name)==0)return this;
	if(_m!=NULL)return _m->search(who);
	if(_f==NULL)return _f->search(who);
	return NULL;
}
void Tree :: change(string name, int depth){
	_name=name;
	_depth=depth;
}