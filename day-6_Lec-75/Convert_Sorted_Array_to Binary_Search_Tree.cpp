
class Solution {
    private:
    TreeNode* makeBST(vector<int>& nums,int s, int e){
        if(s>e){
            return NULL;
        }
       int mid = (s+e)/2;
        TreeNode * newNode = new TreeNode(nums[mid]);
        newNode->left = makeBST(nums,s,mid-1);
        newNode->right = makeBST(nums,mid+1,e);
        return newNode;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        TreeNode* ans = makeBST(nums,i,n-1);
        return ans;
    }
};