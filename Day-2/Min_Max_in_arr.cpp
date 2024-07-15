class Solution {
  public:
    pair<long long, long long> getMinMax(vector<long long int> arr) {
        // code here
        

        if(arr.size()<=1){
            return {arr[0],arr[0]};
        }
        
        int minVal = arr[0];
    int maxVal = arr[0];

    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    return {minVal, maxVal};
    }
};