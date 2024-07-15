#include<vector>
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
         int n = nums.size();
        if (n == 1) return 1;

        int minIndex = 0;
        int maxIndex = 0;

        // Find the indices of the minimum and maximum values
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // Ensure minIndex is less than maxIndex
        if (minIndex > maxIndex) {
            swap(minIndex, maxIndex);
        }

        
        int deletionsFromStart = maxIndex + 1;
        int deletionsFromEnd = n - minIndex;
        int deletionsBothSides = (minIndex + 1) + (n - maxIndex);

        return min({deletionsFromStart, deletionsFromEnd, deletionsBothSides});
    }
};