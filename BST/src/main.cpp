#include <BST.h>
#include <iostream>


int main()
{
	Tree_Obj new_tree;
	new_tree.Insert(27);
	new_tree.Insert(14);
	new_tree.Insert(35);
	new_tree.Insert(10);
	new_tree.Insert(19);
	new_tree.Insert(31);
	new_tree.Insert(42);
	//My own additional data below:
	new_tree.Insert(7);
	new_tree.Insert(12);
	new_tree.Insert(16);
	new_tree.Insert(20);
	new_tree.LevelOrderPrint();
	new_tree.InOrderPrint();
	// std::cout<<"Yo";
}