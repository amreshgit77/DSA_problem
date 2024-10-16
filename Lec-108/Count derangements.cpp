#define MOD 1000000007
#include <vector>

using namespace std;
long long int solveMem(vector<long long int> &dp, int n) {
  if (n == 1)
    return 0;
  if (n == 2)
    return 1;

  if (dp[n] != -1) {
    return dp[n];
  }

  dp[n] = (n - 1) % MOD *
          (solveMem(dp, n - 1) % MOD + solveMem(dp, n - 2) % MOD) % MOD;

  return dp[n];
}
long long int solveTab(int n) {
  vector<long long int> dp(n + 1, -1);

  dp[1] = 0;
  dp[2] = 1;

  for (int i = 3; i <= n; i++) {
    long long int first = dp[i - 1] % MOD;
    long long int second = dp[i - 2] % MOD;

    long long int sum = (first + second) % MOD;

    long long int ans = ((i - 1) * sum) % MOD;
    dp[i] = ans;
  }

  return dp[n];
}

long long int solveSpace(int n) {

  int prev1 = 1;
  int prev2 = 0;

  if (n == 1)
    return prev2;
  if (n == 2)
    return prev1;

  for (int i = 3; i <= n; i++) {
    long long int first = prev1 % MOD;
    long long int second = prev2 % MOD;

    long long int sum = (first + second) % MOD;

    long long int ans = ((i - 1) * sum) % MOD;

    prev2 = prev1;
    prev1 = ans;
  }
  return prev1;
}
long long int countDerangements(int n) {
  // Write your code here.
  // vector<long long int>dp(n+1,-1);

  // return solveMem(dp,n);
  // return solveTab(n);
  return solveSpace(n);
}