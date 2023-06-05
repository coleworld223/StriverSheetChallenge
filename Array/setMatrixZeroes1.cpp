
//Brute force
//In this approach we go at every element of the grid, say {grid[i][j]}
//and if we find the ele to be 0
//we set whole row i, and whole com j to be 0 in a separate matrix
//tc -> O(n * m) * O(n + m) , O(n * m) for traversing the matrix and O(n + m) for setting zeroes
//sc -> O(n * m)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();

       vector <vector <int>> grid = matrix;
       for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
           if(matrix[i][j] == 0){
             for (int k = 0; k < n; k++){
               grid[k][j] = 0;
             }
             for (int k = 0; k < m; k++){
               grid[i][k] = 0;
             }
           }
         }
       }
       matrix = grid;
    }
};
