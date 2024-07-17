class Solution {
  public:
    void SortedDuplicates(int n, vector<int> &arr) {
        // code here
         vector<int>ans;
       
        sort(arr.begin(),arr.end());
        for(int i =0; i<n-1 ; i++){
            if(arr[i] == arr[i+1] &&(ans.empty() || ans.back() != arr[i])){
                ans.push_back(arr[i]);
                
            }
        }
        
        
        //return ans;
        if(ans.size()<=0) ans.push_back(-1);
        
            sort(ans.begin(),ans.end());
        
        
        for(int num :ans){
            cout<<num<<" ";
        }cout<<endl;
    }
};