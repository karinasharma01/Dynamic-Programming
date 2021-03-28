/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
Example 4:

Input: coins = [1], amount = 1
Output: 1
Example 5:

Input: coins = [1], amount = 2
Output: 2
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i] would be storing the value of the minimum no of coins required 
        //for a sum=i
        int n = coins.size();
        int dp[amount+1];
        //if amount=0
        dp[0]=0;
        //initialization
        for(int i=1;i<=amount;i++)
        {
            dp[i]=amount+1;
        }
        //computing the minimum value of coins reqd for amount ranging from 1 to amount
        for(int i=1;i<=amount;i++)
        {
            //we would be considering the coins whose value is less than the present amount i
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i)
                {
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount]>amount)
            return -1;
        return dp[amount];
    }
};
