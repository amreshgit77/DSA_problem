int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        int ans = 0;
    for (int i = 1; i < n; i++) {
        // If the price is increasing, add the difference to the answer
        if (prices[i] > prices[i - 1]) {
            ans += prices[i] - prices[i - 1];
        }
    }
    return ans;
    }