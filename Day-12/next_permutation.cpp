class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        // code here
        
        int idx = -1;
        for(int i =N-2; i>=0; i--){
            if(arr[i] < arr[i+1]){
                idx = i;
                break;
            }
        }
        
        if(idx ==-1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        for(int i =N-1; i>=idx; i--){
            if(arr[i] > arr[idx]){
                swap(arr[i],arr[idx]);
                break;
            }
        }
        reverse(arr.begin()+idx+1,arr.end());
        return arr;
    }
};