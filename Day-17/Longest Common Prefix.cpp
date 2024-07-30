// Leetcode and code 360 soln . see below for gfg soln
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
      int  n = strs.size();
    for(int i=0; i<strs[0].length(); i++)
    {
        char ch = strs[0][i];
        bool match = true;
        for(int j=1; j<n; j++)
        {
            if(strs[j].size() < i || ch!=strs[j][i])
            {
                match = false;
                break;} }
        if(match == false)
        {
            break;
        }

        else
        {
         ans.push_back(ch);
         }

    }return ans;
    }
};
//

// gfg soln:-
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n = arr.size();
        if (n == 0) return "-1"; 
        if(n ==1) return arr[0];
        
        string ans= "";
        for(int i =0; i<n ; i++){
            
            char ch = arr[0][i];
            bool isPre = true;
            
            for(int j = 1; j<n ; j++){
                
                if(arr[j].size()<=i || ch != arr[j][i]){
                    isPre =  false;
                    break;
                }
            }
            
            if(isPre == false){
                break;
            }
            else{
                ans.push_back(ch);
            }
            
        }
        if(ans.size()<= 0){
            return "-1";
        }
        return ans;
    }
};