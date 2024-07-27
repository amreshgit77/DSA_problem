int getPairsCount(const vector<int>& arr, int k) {
        // code here
         unordered_map<int, int> isPresent;
         int cnt = 0;

    for (int i = 0; i < arr.size(); i++) {
        int complement = k - arr[i];
        if (isPresent.find(complement) != isPresent.end()) {
            cnt+= isPresent[arr[i]];
        }
        isPresent[arr[i]] ++;
    }
    
    return cnt;
         
    }