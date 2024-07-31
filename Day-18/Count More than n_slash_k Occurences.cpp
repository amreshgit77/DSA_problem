int countOccurence(int arr[], int n, int k) {
        // Your code here
        unordered_map<int, int> map_count;
    
    // Count the frequency of each element
    for (int i = 0; i < n; i++) {
        map_count[arr[i]]++;
    }
    
    int countMatch = n / k;
    int ans = 0;
    for (auto i : map_count) {
        
        if (i.second > countMatch) {
            ans++;
        }
    }
    return ans;
    }