#include<algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    int solveMem(int W, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp, int index) {
        // Base case: if no items are left or capacity is 0
        if (index == 0) {
            if (wt[0] <= W) {
                return val[0]; // If only one item can fit in the knapsack
            } else {
                return 0; // No items can fit
            }
        }
        
        // If already computed, return the stored result
        if (dp[index][W] != -1) {
            return dp[index][W];
        }
        
        
       
        
        // Include the current item (if its weight is less than or equal to remaining capacity)
        int incl = 0;
        if (wt[index] <= W) {
            incl = val[index] + solveMem(W - wt[index], wt, val, dp, index - 1);
        }
        
        // Exclude the current item
         int excl = solveMem(W, wt, val, dp, index - 1);
        // Store and return the maximum of including or excluding the item
        dp[index][W] = max(incl, excl);
        
        return dp[index][W];
    }
    
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        
        return solveMem(W, wt, val, dp, n - 1);
    }
};
