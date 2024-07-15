class Solution {
  public:
    void reverseInGroups(vector<long long int> &arr, int k) {
        // code here
            
            int i = 0;
         int n = arr.size();
          while (i < n) {
            int j = min(i + k - 1, n - 1);
            int start = i, end = j;
            
            while (start < end) {
                swap(arr[start], arr[end]);
                start++;
                end--;
            }
            
            i += k;
        }
        
        
    }
};