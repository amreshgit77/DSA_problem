class Node {
public:
    int data;
    int i;
    int j;
    Node(int data, int row, int col) {
        this->data = data;
        i = row;
        j = col;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    pair<int, int> findSmallestRange(int KSortedArray[][N], int n, int k) {
        priority_queue<Node*, vector<Node*>, Compare> minHeap;
        int mini = INT_MAX;
        int maxi = INT_MIN;

        // Push the first element of each list into the minHeap
        for (int i = 0; i < k; i++) {
            int element = KSortedArray[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            minHeap.push(new Node(element, i, 0));
        }

        int start = mini;
        int end = maxi;

        while (!minHeap.empty()) {
            Node* top = minHeap.top();
            minHeap.pop();
            mini = top->data;

            // Update the range if a smaller range is found
            if (maxi - mini < end - start) {
                start = mini;
                end = maxi;
            }

            // If there are more elements in the row of the top element
            if (top->j + 1 < n) {
                maxi = max(maxi, KSortedArray[top->i][top->j + 1]);
                minHeap.push(new Node(KSortedArray[top->i][top->j + 1], top->i, top->j + 1));
            } else {
                break;
            }
        }

        return make_pair(start, end);
    }
};