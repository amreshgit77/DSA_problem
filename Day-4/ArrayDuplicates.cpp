vector<int> duplicates(vector<long long> arr) {
        // code here
        int n = arr.size();
        vector<int>ans;
        int temp = -1;
        sort(arr.begin(),arr.end());
        for(int i =0; i<n ; i++){
            if(arr[i] == arr[i+1]){
                ans.push_back(arr[i]);
                
            }
        }
        if(ans.size()<= 0) ans.push_back(-1);
        
        return ans;
    }