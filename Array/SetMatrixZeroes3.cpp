
//can we further optimise the space

//Optimisation 1
//if we can find some integer value which is not present in matrix 
//then we can use it as a substitue for the the orignial zeroes which were there 
//in the matrix, this would reduce the sc to O(1), though it will take O(2 * (n * m)) * O(n + m) time
//But this is not applicable in the present problem as the range is [INT_MIN, INT_MAX]
//so there are no available integers

//Optimisation 2
//As we stored the rows and cols vector in the prev submission
//can we use the space in the matrix itself to store whether a row or col contains a zero or not
//we can use the first row ele and first col ele for that purpose
//also since for 0th row and 0th col there is a collision since only one matrix element {0, 0} is present
//we can have an extra variable which will store for the 0th row or col
//tc -> O(2 * (n * m)) , sc -> O(1)

//Let's look at the implementation of the 2nd approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int m = matrix[0].size();
       int x = 1; //it will store for the 0th row

       for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
           if(matrix[i][j] == 0){
             //special case 
             if(i == 0){
               x = 0;
               matrix[0][j] = 0;
             }
             else{
               matrix[i][0] = 0;
               matrix[0][j] = 0;
             }
           }
         }
       }
       
       for (int i = 1; i < n; i++) { 
         for (int j = 1; j < m; j++) { 
           if(matrix[i][0] == 0 || matrix[0][j] == 0){
             matrix[i][j] = 0;
           }
         }
       }

       if(matrix[0][0] == 0){
         for (int i = 0; i < n; i++) { 
           matrix[i][0] = 0;
         }
       }
       if(x == 0){
         for (int i = 0; i < m; i++) {
           matrix[0][i] = 0;
         }
       }
    }
};
