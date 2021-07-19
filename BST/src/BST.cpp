#include <BST.h>
#include <cstddef>

Tree_Obj::Tree_Obj(): _root(NULL)
{
	_init = true;
}


void Tree_Obj::Insert(int key)
{
	TreeNode **cur_node_ptr = &_root;
	while(true) {
		if(*cur_node_ptr == nullptr) {
			*cur_node_ptr = new TreeNode(key);
			return;
		}
		if(key > (*cur_node_ptr)->val) {
			cur_node_ptr = &((*cur_node_ptr)->right);
		}
		else if(key < (*cur_node_ptr)->val) {
			cur_node_ptr = &((*cur_node_ptr)->left);
		}
	}
}


// Traverse: left->root->right
void Tree_Obj::InOrder(TreeNode *node = NULL)
{
	// Left
	if(node->left) InOrder(node->left);

	// Root
	std::cout<<node->val<<",";

	// Right
	if(node->right) InOrder(node->right);
}

// Traverse: root->left->right
void Tree_Obj::PreOrder(TreeNode *node = NULL)
{
	// Root
	std::cout<<node->val<<",";

	// Left
	if(node->left) InOrder(node->left);

	// Right
	if(node->right) InOrder(node->right);

}

// Tracers: left->right->root
void Tree_Obj::PostOrder(TreeNode *node = NULL)
{
	// Left
	if(node->left) InOrder(node->left);

	// Right
	if(node->right) InOrder(node->right);

	// Root
	std::cout<<node->val<<",";
}

void Tree_Obj::LevelOrder()
{
	std::list<TreeNode*> open_list;
	TreeNode *cur_node;
	open_list.push_back(_root);
	while(!open_list.empty()) {
		cur_node = open_list.front();
		_path.push_back(cur_node->val);
		if(cur_node->left) open_list.push_back(cur_node->left);
		if(cur_node->right) open_list.push_back(cur_node->right);
		open_list.pop_front();
	}
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