#include <BST.h>
#include <cstddef>

Tree_Obj::Tree_Obj(): _root(NULL)
{
	_init = true;
}


// Algo: Look at current node,
// If current node is nullptr add the key(element being inserted)
// If key < cur_node->val, push to left
// else push to cur_node->right
void Tree_Obj::Insert(int key)
{
	// TODO: Fill In Implementation of Insertion into BST
	return;
}


// Traverse: left->root->right
void Tree_Obj::InOrder(TreeNode *node = NULL)
{
	// TODO: Fill In Implementation of In Order Traversal
	return;
}

// Traverse: root->left->right
void Tree_Obj::PreOrder(TreeNode *node = NULL)
{
	// TODO: Fill In Implementation of Pre Order Traversal
	return;
}

// Traverse: left->right->root
void Tree_Obj::PostOrder(TreeNode *node = NULL)
{
	// TODO: Fill In Implementation of Post Order Traversal
	return;
}

// Traverse: Breadth First Search and save shortest path in member variable _path
void Tree_Obj::LevelOrder()
{
	// TODO: Fill In Implementation of LevelOrder/Breadth First Search
	return;
}

void Tree_Obj::LevelOrderPrint()
{
	LevelOrder();
	for(const auto & element :_path)
	{
		std::cout<<element<<",";
	}
	std::cout<<"\n";
}

void Tree_Obj::InOrderPrint() {
	InOrder(_root);
	std::cout<<"\n";
}