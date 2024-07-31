#include <limits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int maxLen = 1;
        int currLen = 1;
        if (nums.empty())
            return 0;
        for (int i = 1; i < N; i++) {
            if (nums[i] == nums[i - 1] + 1) {
                currLen++;
            } else if (nums[i] != nums[i - 1]) {
                maxLen = max(maxLen, currLen);
                currLen = 1;
            }
        }
        maxLen = max(maxLen, currLen);

        return maxLen;
    }
};