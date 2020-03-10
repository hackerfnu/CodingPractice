#include <node.h>
#include <list>
#include <vector>
#include <iostream>

class Tree_Obj
{

	private:
		TreeNode *_root;
		bool _init;
		std::list<TreeNode*> _open_list;
		std::vector<int> _path;
	public:
		Tree_Obj();
		void Insert(int key);
		void Delete(int key);
		void PreOrder(TreeNode *node);
		void PostOrder(TreeNode *node);
		void InOrder(TreeNode *node);
		void LevelOrder(TreeNode *node);
		void LevelOrderPrint();
};
