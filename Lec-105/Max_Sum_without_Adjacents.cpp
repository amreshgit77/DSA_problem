#include<algorithm>
#include <vector>
#include<limits>
using namespace std;

int solveRec(int *arr, int n){
	    if(n == 0){
	        return arr[n];
	    }
	    if(n<0){
	        return 0;
	    }
	    int inc = solveRec(arr,n-2) + arr[n];
	    int exl = solveRec(arr,n-1) +0;
	    
	    int ans = max(inc,exl);
	    return ans;
	}
	
	int solveMem(int *arr, vector<int>&dp, int n){
	    if(n == 0){
	        return arr[n];
	    }
	    if(n<0){
	        return 0;
	    }
	    
	    if(dp[n] != -1)
	    {
	        return dp[n];
	    }
	    int inc = solveMem(arr,dp,n-2) + arr[n];
	    int exl = solveMem(arr,dp,n-1) +0;
	    
	    dp[n] = max(inc,exl);
	    return dp[n];
	    
	}
	int solveTab(int *arr, int n){
	    
	    vector<int>dp(n,-1);
	    dp[0] = arr[0];
	    
	    for(int i = 1; i<n; i++){
	        int inc = dp[i-2]+arr[i];
	        int exl = dp[i-1]+0;
	         dp[i] = max(inc,exl);
	    }

	    return dp[n-1];
	    
	}
	
	int findMaxSum(int *arr, int n) {
	    // code here
	    // Normal Recursion method
	    //return solveRec(arr,n-1);
	    
	    // memoisation
	   // vector<int>dp(n,-1);
	   // return solveMem(arr,dp,n-1);
	    
	    // TAbulation 
	    return solveTab(arr,n);
	}