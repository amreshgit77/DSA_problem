#include<algorithm>
#include <vector>
#include<limits.h>
using namespace std;

#include <bits/stdc++.h> 

int solve(vector<int>& num ,vector<int>& dp ,int x ){
    if(x==0){
        return 0;
    }
    if(x<0){
        return INT_MAX;
    }
    if(dp[x]!= -1){
        return dp[x];
    }
     int mini = INT_MAX;
    for(int i = 0; i<num.size(); i++){
          int ans = solve(num,dp, x-num[i]);
          if(ans!=INT_MAX){
          mini = min(mini,ans+1);
          }
    }
    dp[x] = mini;
    return dp[x];
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
   vector<int>dp(x+1,-1);
  int result = solve(num, dp, x);

    // If result is still INT_MAX, return -1 (not possible to form the sum)
    return result == INT_MAX ? -1 : result;
}