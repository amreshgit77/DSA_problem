#include <vector>
#define MOD 1000000007

using namespace std;
class Solution {
private:

    long long add(long long a, long long b) {
        return (a % MOD + b % MOD) % MOD;
    }

    long long mul(long long a, long long b) {
        return ((a % MOD) * (b % MOD)) % MOD;
    }

    long long solveMem(int n, int k, vector<long long>& dp) {
        if (n == 1) return k;
        if (n == 2) return add(k, mul(k, k - 1));

        if (dp[n] != -1) return dp[n];

        dp[n] = add(mul(solveMem(n - 1, k, dp), k - 1), mul(solveMem(n - 2, k, dp), k - 1));

        return dp[n];
    }
    
    long long solveTab(int n, int k) {
        vector<long long> dp(n + 1, -1);
        
        dp[1] = k;
        dp[2] = add(k, mul(k, k - 1));
        
        
        for(int i =3; i<=n ; i++){
            
            long long diff = mul(dp[i-1],k-1);
            long long same = mul(dp[i-2], k-1);
            
            dp[i] = add(diff,same);
        }

        return dp[n];
    }
    long long solveSpace(int n, int k) {
        
        if (n == 1) return k;
        if (n == 2) return add(k, mul(k, k - 1));
        
        long long prev2 = k;
        long long prev1 = add(k, mul(k, k - 1));
        
        
        for(int i =3; i<=n ; i++){
            
            long long diff = mul(prev2,k-1);
            long long same = mul(prev1, k-1);
            
           long long ans = add(diff,same);
            
            prev2= prev1;
            prev1 = ans;
        }

        return prev1;
    }

public:
    long long countWays(int n, int k) {
        
       // return solveMem(n, k, dp);
       
     //  return solveTab(n,k);
       return solveSpace(n,k);
    }
};