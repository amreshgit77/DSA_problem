double median(vector<int>& a, vector<int>& b) {
	// Write your code here.
	 int n1 = a.size();
    int n2 = b.size();
    int i = n1 - 1;  // Start from the last element of a
    int j = 0;       // Start from the first element of b

    // Swap elements to maintain order
    while (i >= 0 && j < n2) {
        if (a[i] > b[j]) {
            swap(a[i], b[j]);
            i--;
            j++;
        } else {
            break;
        }
    }

    // Sort both y1ys
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> temp(n1 + n2);
    i = 0;
    j = 0;
    int k = 0;

    // Merge both sorted arrays into temp
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = b[j++];
        }
    }

    // Copy any remaining elements of a
    while (i < n1) {
        temp[k++] = a[i++];
    }

    // Copy any remaining elements of b
    while (j < n2) {
        temp[k++] = b[j++];
    }

    int totalSize = n1 + n2;
    int mid1 = totalSize / 2;
    int mid2 = mid1 - 1;

    // Calculate the median
    if (totalSize % 2 == 0) {
        double val = (temp[mid1] + temp[mid2]) / 2.0;
        return val;
    } else {
        return temp[mid1];
    }
    
}