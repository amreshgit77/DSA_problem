
class Solution {
    private:
    int countNode(struct Node* tree){
        if(tree == NULL){
            return 0;
        }
        int left = countNode(tree->left);
        int right =countNode(tree->right);
        
        int count = left+right+1;
        return count;
        
    }
    bool maxOrder(struct Node* tree ){
        if (tree == NULL) {
            return true;
        }
        
        bool leftCheck = true, rightCheck = true;
        
        if (tree->left) {
            leftCheck = (tree->data >= tree->left->data) && maxOrder(tree->left);
        }
        if (tree->right) {
            rightCheck = (tree->data >= tree->right->data) && maxOrder(tree->right);
        }

        return leftCheck && rightCheck;
    }
    bool isCBT(struct Node* tree,int index,int totalcount){
        if(tree == NULL){
            return true;
        }
        if(index>= totalcount){
            return false;
        }
        else{
            bool left =  isCBT(tree->left, index*2+1 , totalcount);
            bool right =  isCBT(tree->right, index*2+2 , totalcount);
             return( left&&right);
        }
    }
  public:
    bool isHeap(struct Node* tree) {
        // code here
        int index = 0;
        int totalcount = countNode(tree);
        if(isCBT(tree,index,totalcount) && maxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};