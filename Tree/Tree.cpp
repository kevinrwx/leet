
//Binary Tree Inorder Traversal
// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// struct TreeNode {
// 	int val;
// 	TreeNode* left;
// 	TreeNode* right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// //采用递归的方法进行二叉树的遍历
// void inorderTrav(TreeNode* root, vector<int>& result) {
//     if(root != NULL) {
//         inorderTrav(root->left, result);
//         result.push_back(root->val);
//         inorderTrav(root->right, result);
//     }
// }

// vector<int> inorderTraversal(TreeNode* root) {
//     vector<int> result;
//     if(root == NULL)
//         return result;
//     inorderTrav(root, result);
//     return result;
// }

// //采用非递归的方法进行二叉树的遍历
// vector<int> inorderTrav(TreeNode* root) {
//     vector<int> result;
//     if(root == NULL)
//     	return result;
//     TreeNode* pNode = root;
//     stack<TreeNode*> st;
//     while(pNode != NULL || !st.empty()) {
//     	while(pNode != NULL) {
//     		st.push(pNode);
//     		pNode = pNode->left;
//     	}
//     	if(!st.empty()) {
//     		pNode = st.top();
//     		st.pop();
//     		result.push_back(pNode->val);
//     		pNode = pNode->right;
//     	}
//     }
//     return result;
// }

// vector<int> inorderTraversal(TreeNode* root) {
//     vector<int> result = inorderTrav(root);
//     return result;
// }


// int main() {
// 	TreeNode* root = new TreeNode(1);
// 	root->left = new TreeNode(2);
// 	root->right = new TreeNode(3);
// 	root->left->left = new TreeNode(4);

// 	vector<int> result = inorderTraversal(root);
// 	for(int i = 0; i < result.size(); i++)
// 		cout<<result[i]<<" ";
// 	cout<<endl;
// 	return 0;
// }


//Unique Binary Search Trees II
// #include <iostream>
// #include <vector>

// using namespace std;

// struct TreeNode {
// 	int val;
// 	TreeNode* left;
// 	TreeNode* right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// vector<TreeNode*> genBST(int min, int max) {
// 	vector<TreeNode*> result;
// 	if(min > max) {
// 		result.push_back(NULL);
// 		return result;
// 	}
// 	for(int i = min; i <= max; i++) {
// 		vector<TreeNode*> leftTree = genBST(min, i-1);
// 		vector<TreeNode*> rightTree = genBST(i+1, max);
// 		for(int j = 0; j < leftTree.size(); j++) {
// 			for(int k = 0; k < rightTree.size(); k++) {
// 				TreeNode* root = new TreeNode(i);
// 				root->left = leftTree[j];
// 				root->right = rightTree[k];
// 				result.push_back(root);
// 			}
// 		}
// 	}
// 	return result;
// }

// vector<TreeNode*> generateTrees(int n) {
// 	vector<TreeNode*> result;
// 	if(n <= 0)
// 		return result;
// 	result = genBST(1, n);
// 	return result;
// }

// int main() {
// 	//
// }


//Unique Binary Search Trees
// #include <iostream>
// #include <vector>

// using namespace std;

// struct TreeNode {
// 	int val;
// 	TreeNode* left;
// 	TreeNode* right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// int numTrees(int n) {
//     if(n <= 0)
//         return 1;
//     vector<int> tmp(n+1, 0);
//     tmp[0] = 1;
//     tmp[1] = 1;
//     for(int i = 2; i <= n; i++) {
//         for(int j = 0; j < i; j++)
//             tmp[i] = tmp[i] + tmp[j]*tmp[i-j-1];
//     }
//     return tmp[n];
// }

// int main() {
// 	//
// }

//Validate Binary Search Tree
// #include <iostream>
// #include <vector>
// #include <stack>

// using namespace std;

// struct TreeNode {
// 	int val;
// 	TreeNode* left;
// 	TreeNode* right;
// 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

// vector<int> inorderTraversal(TreeNode* root) {
// 	vector<int> result;
// 	if(root == NULL)
// 		return result;
// 	TreeNode* pNode = root;
// 	stack<TreeNode*> st;
// 	while(pNode != NULL || !st.empty()) {
// 		while(pNode != NULL) {
// 			st.push(pNode);
// 			pNode = pNode->left;
// 		}
// 		if(!st.empty()) {
// 			pNode = st.top();
// 			st.pop();
// 			result.push_back(pNode->val);
// 			pNode = pNode->right;
// 		}
// 	}
// 	return result;
// }

// //利用二叉搜索树的性质，即先进行中序遍历，然后再判断结果是否有顺序，如果逆序，则不是二叉树
// bool isValidBST(TreeNode* root) {
// 	if(root == NULL || (root != NULL && root->left == NULL && root->right == NULL))
// 		return true;
// 	vector<int> result = inorderTraversal(root);
// 	for(int i = 0; i < result.size()-1; i++) {
// 		if(result[i] >= result[i+1])
// 			return false;
// 	}
// 	return true;
// }

// int main() {
// 	TreeNode* root = new TreeNode(4);
// 	root->left = new TreeNode(4);
// 	// root->right = new TreeNode(3);
// 	if(isValidBST(root)) {
// 		cout<<"valid BST"<<endl;
// 	} else {
// 		cout<<"not valid"<<endl;
// 	}
// 	return 0;
// }

//Recover Binary Search Tree
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional> 


using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderTraversal(TreeNode* root, vector<int>& tmp, vector<TreeNode*>& result) {
	if(root == NULL)
		return ;
	TreeNode* pNode = root;
	stack<TreeNode*> st;
	while(pNode != NULL || !st.empty()) {
		while(pNode != NULL) {
			st.push(pNode);
			pNode = pNode->left;
		}
		if(!st.empty()) {
			pNode = st.top();
			st.pop();
			tmp.push_back(pNode->val);
			result.push_back(pNode);
			pNode = pNode->right;
		}
	}
}

void recoverTree(TreeNode* root) {
	if(root == NULL || (root != NULL && root->left == NULL && root->right == NULL))
		return ;
	vector<int> tmp;
	vector<TreeNode*> result;
	inorderTraversal(root, tmp, result);
	sort(tmp.begin(), tmp.end());
	for(int i = 0; i < result.size(); i++)
		result[i]->val = tmp[i];
}


int main() {
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(5);
	root->right = new TreeNode(6);
	recoverTree(root);
	return 0;
}






