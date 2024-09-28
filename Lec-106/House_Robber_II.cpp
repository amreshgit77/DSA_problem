#include <bits/stdc++.h>
using namespace std;

long long int solveTab(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if (n == 0) return 0;
    if (n == 1) return valueInHouse[0];

    vector<long long> dp(n, 0);
    
    dp[n-1] = valueInHouse[n-1];  
    dp[n-2] = max(valueInHouse[n-2], valueInHouse[n-1]);  

    // Iterate from the second last house to the first
    for (int i = n-3; i >= 0; i--) {
        long long inc = dp[i + 2] + valueInHouse[i];  
        long long excl = dp[i + 1];                  
        dp[i] = max(inc, excl);                      
    }

    return dp[0];
}

long long int houseRobber(vector<int>& valueInHouse) {
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];  // Only one house to rob

    // Create two scenarios: 
    // 1. Rob houses from index 0 to n-2.
    // 2. Rob houses from index 1 to n-1.

    vector<int> first, second;
    for (int i = 0; i < n; i++) {
        if (i != 0) second.push_back(valueInHouse[i]);  // Exclude the first house
        if (i != n - 1) first.push_back(valueInHouse[i]); // Exclude the last house
    }

    return max(solveTab(first), solveTab(second));
}
