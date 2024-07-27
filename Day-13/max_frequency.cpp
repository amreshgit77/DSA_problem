int maximumFrequency(vector<int> &arr, int n)
{
    //Write your code here
   int maxFre = 0;
    int ans = 0;
    unordered_map<int, int> M;

   
    for (int i = 0; i < arr.size(); i++) {
        M[arr[i]] +=1;
        maxFre = std::max(maxFre, M[arr[i]]);
    }

   
    for (auto i : M) {
        if (maxFre == M[arr[i]]) {
            ans = arr[i];
            break; 
        }
    }

  