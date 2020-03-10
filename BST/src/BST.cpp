#include <BST.h>
#include <cstddef>

Tree_Obj::Tree_Obj(): _root(NULL)
{
	_init = true;
}


void Tree_Obj::Insert(int key)
{
	TreeNode **node_to_check = &_root;
	while(true)
	{
		if((*node_to_check) == NULL)
		{
			(*node_to_check) = new TreeNode(key);
			break;
		}
		else if(key > (*node_to_check)->val)
		{
			// std::cout<<"Key is big"<<key<<"\n";
			node_to_check = &((*node_to_check)->right);
		}
		else
		{
			// std::cout<<"Key is small"<<key<<"\n";
			node_to_check = &((*node_to_check)->left);
		}
	}

}


void Tree_Obj::InOrder(TreeNode *node = NULL)
{
	if(_init == true)
	{
		_init = false;
		// std::cout<<(_root->val);
		InOrder(_root);
	}

	if(node != NULL)
	{
		InOrder(node->left);
		std::cout<<node->val<<",";
		InOrder(node->right);
	}
}

void Tree_Obj::PreOrder(TreeNode *node = NULL)
{
	if(_init == true)
	{
		_init = false;
		// std::cout<<(_root->val);
		PreOrder(_root);
	}

	if(node != NULL)
	{
		std::cout<<node->val<<",";
		PreOrder(node->left);
		PreOrder(node->right);
	}
}

void Tree_Obj::PostOrder(TreeNode *node = NULL)
{
	if(_init == true)
	{
		_init = false;
		// std::cout<<(_root->val);
		PostOrder(_root);
	}

	if(node != NULL)
	{
		PostOrder(node->left);
		PostOrder(node->right);
		std::cout<<node->val<<",";
	}
}

void Tree_Obj::LevelOrder(TreeNode *node = NULL)
{
	if(_init == true)
	{
		_init = false;
		_open_list.push_back(_root);
		LevelOrder(_root);
	}

	if(node != NULL)
	{
		_open_list.pop_front();
		_path.push_back(node->val);
		_open_list.push_back(node->left);
		_open_list.push_back(node->right);
		LevelOrder(_open_list.front());
	}
}

void Tree_Obj::LevelOrderPrint()
{
	LevelOrder(0);
	for(const auto & element :_path)
	{
		std::cout<<element<<",";
	}
}