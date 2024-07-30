class Solution {
public:
    void multiply(vector<int>& res, int& size, int multiplier) {
        int carry = 0;
        for (int i = 0; i < size; i++) {
            int temp = res[i] * multiplier;
            temp+= carry;
            res[i] = temp % 10;
            carry = temp / 10;
        }
        
        while (carry > 0) {
            // if (size >= res.size()) {
            //     res.push_back(0); // Ensure we have enough space
            // }
            res[size] = carry % 10;
            carry /= 10;
            size++;
        }
    }

    vector<int> factorial(int N) {
        if (N == 0) return {1};
        
        vector<int> res(10000, 0);
        int size = 1;
        res[0] = 1;
        
        for (int i = 2; i <= N; i++) {
            multiply(res, size, i);
        }
        
        reverse(res.begin(), res.begin() + size);
        res.resize(size);
        
        return res;
    }
};