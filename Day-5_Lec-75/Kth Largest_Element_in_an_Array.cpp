class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i<k; i++){
            pq.push(nums[i]);
        }
        int r =  nums.size();
        for(int i = k; i<r; i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }
};