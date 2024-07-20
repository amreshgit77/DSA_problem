#include <iostream>
#include <vector>
#include <queue>
void inOrderTraversal(BinaryTreeNode* root, vector<int>&inOrder){
     if(root == NULL){
		 return;
	 }

	 inOrderTraversal(root->left,  inOrder);
	 inOrder.push_back(root->data);
	 inOrderTraversal(root->right,inOrder);
}
BinaryTreeNode* preorder(vector<int>&inOrder, int &index){
       if(index >=inOrder.size()){
		   return NULL;
	   }
	   BinaryTreeNode* newNode = new BinaryTreeNode(inOrder[index++]);

	   newNode->left = preorder(inOrder,index);
	   newNode->right = preorder(inOrder,index);
	   return newNode;

}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int>inOrder;
	inOrderTraversal(root, inOrder);
	int index =0;
   BinaryTreeNode* ans = preorder(inOrder,index);
   return ans;

}