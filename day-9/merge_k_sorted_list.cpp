class compare{
    public:
    bool operator()(Node*a,Node*b){
        return a->data>b->data;
    }
};
class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           priority_queue<Node*, vector<Node*>, compare> minHeap;
           
           for(int i =0; i<K;i++){
               if (arr[i] != nullptr) {
                minHeap.push(arr[i]);
              }
           }
           Node* head = NULL;
           Node* tail = NULL;
           
           while(!minHeap.empty()){
               Node * top = minHeap.top();
               minHeap.pop();
               if(head == NULL){
                   head = top;
                   tail = top;
               }
               else{
                   tail ->next = top;
                   tail = top;
               }
               if(tail->next!= NULL){
                   minHeap.push(tail->next);
               }
           }
           return head;
    }
};
