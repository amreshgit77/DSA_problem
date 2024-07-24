class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
       
	priority_queue < int, vector<int>, greater<int> > minH;
	for(int i = 0; i<N; i++){
		int sum =0;
		for(int j = i; j<N ; j++){
            sum  = sum+Arr[j];
			if(minH.size()<K){
				   minH.push(sum);
			}
		    else{
			     if(sum>minH.top()){
					minH.pop();
					minH.push(sum);
				}
		    }
	    }
	}
	return minH.top();
    }
};