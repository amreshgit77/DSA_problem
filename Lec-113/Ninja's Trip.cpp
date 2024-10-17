#include<algorithm>
#include <vector>
#include<limits.h>
using namespace std;

int solveMem(int n, vector<int> days, vector<int> cost,int index, vector<int>&dp){
    if(index >= n) return 0;
    
    if(dp[index] != -1) return dp[index];
    // for 1 days 
    int option1 = cost[0] + solveMem(n,days,cost,index+1,dp);

    // for 7 days
    int i ;
    for( i =index; i<n && days[i]<days[index] +7 ; i++);

    int option2 = cost[1] + solveMem(n,days,cost,i ,dp);
     // for 30 days
     for( i =index; i<n && days[i]<days[index] +30 ; i++);
     
    int option3 = cost[2] + solveMem(n,days,cost,i ,dp);
    
    // min cost
    dp[index] = min(option3 ,min(option2,option1));

     return dp[index];
}

int solveTab(int n, vector<int> days, vector<int> cost){
    vector<int>dp(n+1, INT_MAX);

    dp[n] = 0;

    for(int k = n-1 ; k>=0; k--){

        int option1 = cost[0] + dp[k+1];

    // for 7 days
    int i ;
    for( i =k; i<n && days[i]<days[k] +7 ; i++);

    int option2 = cost[1] + dp[i];
     // for 30 days
     for( i =k; i<n && days[i]<days[k] +30 ; i++);
     
    int option3 = cost[2] + dp[i];
    
    // min cost
       dp[k] = min(option3 ,min(option2,option1));

    }

    return dp[0];
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    // Write your code here.
    vector<int>dp(n+1,-1);

    //return solveMem(n,days,cost,0,dp);

    return solveTab(n,days,cost);
}