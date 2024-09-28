#include<algorithm>
#include <vector>
using namespace std;

int solve(vector<int>&cost ,int n, vector<int>&dp){
    // TOP - DOWN method
        if(n==0 ){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = min(solve(cost,n-1,dp),solve(cost,n-2,dp)) + cost[n];
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        //Write your code here
        // vector<int>dp(N+1 , -1);
        // int ans = min(solve(cost,N-1,dp), solve(cost,N-2,dp));
        // return ans;

        // Space optimization method
        int prev1 = cost[1];
        int prev2 = cost[0];
        int curr = 0;
        for(int i = 2; i<N; i++){
            
            curr = min( prev1, prev2 ) +cost[i] ;
            
            prev2 = prev1;
            prev1 = curr;
            
        }
        return min(prev1, prev2);
    }