class Solution
{
    public:
    
    long long minCost(long long arr[], long long n) {
        // Your code here
         priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (long long i = 0; i < n; ++i) {
        pq.push(arr[i]);
    }

    long long ans = 0;

   
    while (pq.size() > 1) {
        
        long long top1 = pq.top();
        pq.pop();
        long long top2 = pq.top();
        pq.pop();

       
        long long sum = top1 + top2;
        ans += sum;

        pq.push(sum);
    }

    return ans;
    }
};