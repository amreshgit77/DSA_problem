#include<queue>
int signum(int data1,int data2){
	if(data1== data2){
		return 0;
	}
	else if(data1>data2){
		return 1;
	}
	else{
		return -1;
	}
}
void callMedian(int element,priority_queue < int>&maxi,
priority_queue < int, vector<int>, greater<int> >&mini,int &median )
{    
	switch(signum(maxi.size(),mini.size())){
		case 0:
		if(element>median){
			mini.push(element);
			median = mini.top();
		}
		else{
			maxi.push(element);
             median = maxi.top();
		}
		break;
		case 1:
		if(element>median){
			mini.push(element);
			median = (mini.top()+maxi.top())/2;
		}
		else{
			mini.push(maxi.top());
			maxi.pop();
			maxi.push(element);
			median = (mini.top()+maxi.top())/2;
		}
		break;
		case -1:
		if(element>median){
			maxi.push(mini.top());
			mini.pop();
			mini.push(element);
			median = (mini.top()+maxi.top())/2;
		}
		else{
           maxi.push(element);
		   median = (mini.top()+maxi.top())/2;
		}
		break;


	}

}
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
    priority_queue < int>maxi;
	priority_queue < int, vector<int>, greater<int> > mini;
	 vector<int>ans;
	 int median = 0;

	 for(int i =0; i<n; i++){
		 callMedian(arr[i],maxi,mini,median);
		 ans.push_back(median);
	 }
	 return ans;
	 
}
