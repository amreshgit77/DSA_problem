class Solution{
public:	
	void reverseSubArray(int *arr, int n, int l, int r) {
	    // code here
	    while (l < r) {
            swap(arr[l-1], arr[r-1]);
            l++;
            r--;
        }
	}

};