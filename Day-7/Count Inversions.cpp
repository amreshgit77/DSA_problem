class Solution {
private:
    void merge(long long arr[], int s, int e, long long &inversion) {
        if (s >= e) {
            return;
        }
        int mid = (s + e) / 2;
        merge(arr, s, mid, inversion);
        merge(arr, mid + 1, e, inversion);
        merge_sort(arr, s, e, inversion);
    }

    void merge_sort(long long arr[], int s, int e, long long &inversion) {
        int mid = (s + e) / 2;
        int len1 = mid - s + 1;
        int len2 = e - mid;

        long long* arr1 = new long long[len1];
        long long* arr2 = new long long[len2];

        for (int i = 0; i < len1; ++i) {
            arr1[i] = arr[s + i];
        }
        for (int j = 0; j < len2; ++j) {
            arr2[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = s;
        while (i < len1 && j < len2) {
            if (arr1[i] <= arr2[j]) {
                arr[k++] = arr1[i++];
            } else {
                arr[k++] = arr2[j++];
                inversion += (len1 - i); // Count inversions
            }
        }
        while (i < len1) {
            arr[k++] = arr1[i++];
        }
        while (j < len2) {
            arr[k++] = arr2[j++];
        }

        delete[] arr1;
        delete[] arr2;
    }

public:
    long long int inversionCount(long long arr[], int n) {
        long long inversion = 0;
        merge(arr, 0, n - 1, inversion);
        return inversion;
    }
};