#include <vector>

using namespace std;

// Process
// 1. Input image 2d vector
// 2. Make reverse number vector
// 3. Make bitnot vector
// 4. Return vector

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		for (int i = 0; i < A.size(); ++i) {
			reverse(A[i].begin(), A[i].end());
		}

		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < A[i].size(); ++j) {
				A[i][j] = abs(A[i][j] - 1);
			}
		}

		return A;
	}
};