/*Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:
Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:
Input: matrix = [["0"]]
Output: 0
*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
    int maxSize = 0;
        int m=matrix.size();
        int n=matrix[0].size();
        int dp[m][n];
        for(int i=0;i<matrix.size();i++)
        {
            dp[i][0]=matrix[i][0]-'0';
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            dp[0][j]=matrix[0][j]-'0';
        }
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=1;j<matrix[0].size();j++)
            {
                if(matrix[i][j]=='0')
                {
                    dp[i][j]=0;
                }
                else if(matrix[i][j]=='1')
                {
                    dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(maxSize<dp[i][j])
                {
                    maxSize=dp[i][j];
                }
            }
        }
          int maxArea =maxSize*maxSize;
        return maxArea;
    }
};
