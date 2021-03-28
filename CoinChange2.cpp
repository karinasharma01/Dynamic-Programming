/*
You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount.
You may assume that you have infinite number of each kind of coin.
Example 1:

Input: amount = 5, coins = [1, 2, 5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10] 
Output: 1
Note:
You can assume that
0 <= amount <= 5000
1 <= coin <= 5000
the number of coins is less than 500
the answer is guaranteed to fit into signed 32-bit integer
*/

class Solution {
public:
    /*int countWays(int amount,int n,vector<int>& coins)
    {
        if(amount==0)
        {
            return 1;//do not include any coin
        }
        if(amount<0)
        {
            return 0;
        }
        if(n<=0 && amount>0)
        {
            return 0;
        }
        //including the nth coin
        int c1=countWays(amount-coins[n-1],n,coins);
        int c2=countWays(amount,n-1,coins);
        return (c1+c2);
    }*/
    int countWays(int amount,int n,vector<int>& coins)
    {
       if(n<=0 && amount>0)
        {
            return 0;
        }
        int dp[amount+1][n];
        int c1,c2;
        //dp[i][j] is the total no of ways to obtain an amount=i using the first j coins 
        //we are taking amount+1 rows since we are considering the base case
        //when amount=0 and the table is being constructed in bottom up approach
        for(int i=0;i<n;i++)
        {
            dp[0][i]=1;
        }
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<n;j++)
            {
                //count of solutions using coins[j]
                if(i-coins[j]>=0)
                {
                    c1=dp[i-coins[j]][j];
                }
                else
                {
                    c1=0;
                }
                //count of solutions excluding coins[j]
                if(j>=1)
                {
                    c2=dp[i][j-1];
                }
                else
                {
                    c2=0;
                }
                dp[i][j]=c1+c2;
            }
        }
        return dp[amount][n-1];
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        //n is the total no of coins
        return countWays(amount,n,coins);
        
    }
};
