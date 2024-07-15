#include <iostream>
using namespace std;

class heap {
public:
    int size;
    int arr[100];

    heap() {
        size = 0;
        arr[0] = -1; // -1 is a placeholder and won't be used
    }

    void insertion(int data) {
        size = size + 1;
        int index = size;
        arr[index] = data;
        
        while (index > 1) {
            int parent = index / 2;
            if (arr[index] > arr[parent]) {
                swap(arr[index], arr[parent]);
                index = parent;
            } else {
                return;
            }
        }
    }
    
    void deletetion( int index){
         
            arr[index] =arr[size];
        
         size --;
         while(index<= size){
            int leftidx =  2*index;
            int rightidx = 2*index +1;

            if(leftidx<size &&  arr[index] <arr[leftidx]){
                swap(arr[index] ,arr[leftidx]);
                index = leftidx;
            }
            else if(rightidx<size && arr[index] <arr[rightidx]){
                swap(arr[index] ,arr[rightidx]);
                 index = leftidx;
            }
            else{
                return;
            }
         }
    }
    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    heap h;
    h.insertion(25);
    h.insertion(27);
    h.insertion(23);
    h.insertion(29);
    h.insertion(33);

    h.print();
    // h.deletetion(1);
    // h.print();
    h.deletetion(3);
    h.print();

    return 0;
}
