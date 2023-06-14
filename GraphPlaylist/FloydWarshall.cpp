class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int N = matrix.size();
	    
	    for (int i = 0; i < N; i++) {
	        for (int j = 0; j < N; j++) {
	            if(matrix[i][j] == -1)matrix[i][j] = 1e9;
	        }
	        matrix[i][i] = 0;
	    }
	    
	    for (int k = 0; k < N; k++) {
	        for (int i = 0; i < N; i++) {
	            for (int j = 0; j < N; j++) {
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }
	    
	    
	    for (int i  = 0; i < N; i++) {
	        for (int j = 0; j < N; j++) {
	            if(matrix[i][j] == 1e9) matrix[i][j] = -1;
	        }
	    }
	}
};
