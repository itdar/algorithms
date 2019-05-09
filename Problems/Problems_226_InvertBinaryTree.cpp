#include <vector>
#include <iostream>

using namespace std;


 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (root != 0) {
			vector<int> *treeBuff = new vector<int>();

			makeVector(treeBuff, root);

			if (treeBuff->size() > 0)
				makeTree(treeBuff, root);
		}
		return root;
	}
private:
	void makeVector(vector<int> *treeBuff, TreeNode* node) {
		makeVectorRecursive(treeBuff, node);
	}
	void makeVectorRecursive(vector<int> *treeBuff, TreeNode* node) {
		if (node->left != 0)
			makeVectorRecursive(treeBuff, node->left);

		if (node != 0)
			treeBuff->push_back(node->val);

		if (node->right != 0)
			makeVectorRecursive(treeBuff, node->right);
	}

	void makeTree(vector<int> *treeBuff, TreeNode* node) {
		if (node->right != 0)
			makeTree(treeBuff, node->right);

		node->val = treeBuff->at(0);
		treeBuff->erase(treeBuff->begin() + 0);
		
		makeTree(treeBuff, node->left);
	}
};