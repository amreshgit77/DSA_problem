bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> prefixSums;
    int sum = 0;

    // Traverse the array
    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Update the cumulative sum
        
        // Check if cumulative sum is zero or has been seen before
        if (sum == 0 || prefixSums.find(sum) != prefixSums.end()) {
            return true; // Zero-sum subarray exists
        }
        
        // Add the cumulative sum to the set
        prefixSums.insert(sum);
    }
    
    return false; 
    }