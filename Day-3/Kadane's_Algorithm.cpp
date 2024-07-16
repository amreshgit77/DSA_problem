class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(vector<int> &arr) {
        // code here...
        long long sum = INT_MIN;
        long long  curr =0;;
        int i =0;
        while(i<arr.size()){
            curr = curr+arr[i];
            if(sum<curr){
                sum = curr;
            }
            if(curr<0){
                curr = 0;
            }
            i++;
        }
        return sum;
    }
};