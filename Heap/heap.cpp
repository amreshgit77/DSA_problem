#include <iostream>
using namespace std;

class heap
{
public:
    int size;
    int arr[100];

    heap()
    {
        size = 0;
        arr[0] = -1; // -1 is a placeholder and won't be used
    }

    void insertion(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[index] > arr[parent])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletetion(int index)
    {

        arr[index] = arr[size];

        size--;

        while (index <= size)
        {
            int leftidx = 2 * index;
            int rightidx = 2 * index + 1;
            int largest = index;

            if (leftidx <= size && arr[largest] < arr[leftidx])
            {
                largest = leftidx;
            }
            if (rightidx <= size && arr[largest] < arr[rightidx])
            {
                largest = rightidx;
            }

            if (largest != index)
            {
                swap(arr[index], arr[largest]);
                index = largest;
            }
            else
            {
                break;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right <= n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}

int main()
{
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

    int arr[6] = {-1, 33, 29, 23, 25, 27};
    int n = 5;
    // heap building
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
        cout << "After Heapify" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "heap sorting" << endl;

    heapSort(arr, n);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
