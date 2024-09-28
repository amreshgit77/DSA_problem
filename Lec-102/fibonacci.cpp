#include<algorithm>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<long long int> dp;  // Declare dp as a member variable
    const int MOD = 1e9 + 7; 
    // Top-Down Approach (Memoization)
    long long int topDown(int n) {
       
        if (dp.size() < n + 1) dp.resize(n + 1, -1);
        
        if (n <= 1) {  
            return n;  
        }

        if (dp[n] != -1) {  
            return dp[n];
        }

       
        dp[n] = (topDown(n - 1) + topDown(n - 2))% MOD;
        return dp[n];
    }
    
    // Bottom-Up Approach (Tabulation)
    long long int bottomUp(int n) {
        if (n <= 1) return n;

        
        dp.assign(n + 1, 0);
        dp[1] = 1;  // Base case
        
       
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2])% MOD;
        }

        return dp[n];
    }
};