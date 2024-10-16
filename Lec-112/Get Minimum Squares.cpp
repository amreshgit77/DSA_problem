#include<algorithm>
#include <vector>
#include<limits.h>
using namespace std;

class Solution {
    private:
    
    int solveMem(int n, vector<int>&dp){
        
        if(n==0) return 0;
        
        if(dp[n] != -1) return dp[n] ;
        
        int ans = n;
        
        for(int i = 1; i*i<=n ; i++){
            
            int temp = i*i;
            
            ans = min(ans,solveMem(n-temp,dp)+1);
        }
        
        dp[n] = ans;
        
        return dp[n];
    }
    
    int solveTab(int n){
        vector<int>dp(n+1,INT_MAX);
        
        dp[0] =0;
        
        for(int i = 0; i<=n ; i++){
            
            for(int j = 1; j*j<=n ; j++){
                int temp = j*j;
                
                if(i-temp>=0)
                dp[i] = min(dp[i],dp[i-temp]+1);
            }
        }
        
        return dp[n];
    }
  public:
    int MinSquares(int n) {
        // Code here
        
        vector<int>dp(n+1 ,-1);
        
       // return solveMem(n,dp);
        
        return solveTab(n);
        
    }
};