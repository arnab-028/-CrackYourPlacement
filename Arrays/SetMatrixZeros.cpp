#include <vector>
#include<iostream>


class Solution {
public:
  void setZeroes(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    std::vector<bool> row(m, false);
    std::vector<bool> col(n, false);

    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          row[i] = true;
          col[j] = true;
        }
      }
    }

  
    for (int i = 0; i < m; i++) {
      if (row[i]) {
        std::fill(matrix[i].begin(), matrix[i].end(), 0);
      }
    }

    
    for (int j = 0; j < n; j++) {
      if (col[j]) {
        for (int i = 0; i < m; i++) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
