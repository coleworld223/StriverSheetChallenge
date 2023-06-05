
//little optimisation
//we can optimise the tc and sc from the prev case as
//we can find for each row or col, whether it contains a 0 or not
//and prestore it in some way (can use set, vector, map anything)
//which will tell us in a little time if a particular row or col has 0 in it or not
//finally we traverse a matrix and put 0's accordingly
//tc -> O(n * m) + O(n * m) two traversals(one for storing rows, cols, other for putting 0's)
//sc -> O(n + m) -> since we now have prestored the rows and cols , we can omit the extra grid space
//as the zeroes put till now will not interfere with what will put in future
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();

       vector <int> rows(n, 0);
       vector <int> cols(m, 0);

       for (int i = 0; i < n; i++){
         for (int j = 0; j < m; j++){
           if(matrix[i][j] == 0){
             rows[i] = 1;
             cols[j] = 1;
           }
         }
       }

       for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
           if(rows[i] == 1 || cols[j] == 1){
             matrix[i][j] = 0;
           }
         }
       }
  
    }
};
