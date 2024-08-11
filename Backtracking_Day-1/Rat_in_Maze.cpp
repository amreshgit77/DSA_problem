#include <bits/stdc++.h> 
bool isSafe(int x, int y, vector<vector<int>>& arr, vector<vector<bool>>& visited, int n) {
   
    return (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1 && !visited[x][y]);
}

void solve(vector<vector<int>>& arr, vector<vector<bool>>& visited, vector<string>& ans, string& temp, int n, int x, int y) {
   
    if (x == n-1 && y == n-1) {
        ans.push_back(temp);
        return;
    }
    
    visited[x][y] = true;
    
    // Down
    if (isSafe(x+1, y, arr, visited, n)) {
        temp.push_back('D');
        solve(arr, visited, ans, temp, n, x+1, y);
        temp.pop_back(); // backtrack
    }
    
    // Right
    if (isSafe(x, y+1, arr, visited, n)) {
        temp.push_back('R');
        solve(arr, visited, ans, temp, n, x, y+1);
        temp.pop_back(); // backtrack
    }
    
    // Left
    if (isSafe(x, y-1, arr, visited, n)) {
        temp.push_back('L');
        solve(arr, visited, ans, temp, n, x, y-1);
        temp.pop_back(); // backtrack
    }
    
    // Up
    if (isSafe(x-1, y, arr, visited, n)) {
        temp.push_back('U');
        solve(arr, visited, ans, temp, n, x-1, y);
        temp.pop_back(); // backtrack
    }
    
    // Unmark the current cell as visited immediately after exploring neighbors
    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>>& arr, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<string> ans;
    string temp = "";
    
   
    int x = 0, y = 0;
    
    
    if (arr[x][y] == 0) {
        return ans;
    }
    
    solve(arr, visited, ans, temp, n, x, y);
    return ans;
}

