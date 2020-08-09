/*
Given two strings S and T, find length of the shortest subsequence in S which is not a subsequence in T ie the Shortest Uncommon Subsequence of the two given strings.
Note: input data will be such so there will always be a solution.

Input:
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
Output:
Length of the shortest subsequence in integers.
Sample:
INPUT:
babab
babba
OUTPUT:
3
Explanation:
The length of the shortest subsequence "aab" is 3.
*/
____________________________________________________________________________________________________________________________________________________________________________________
Solution:
#include<iostream>
#include<string>
using namespace std;
#define MAX 1001;
int shortestSeq(string s1,string s2){
int m=s1.size();
    int n=s2.size();
    int dp[m+1][n+1],next[m+1][n+1];
    int i,j,prev;
    for(i=0;i<m;i++){
        prev=-1;
        for(j=0;j<n;j++)
        {
            if(s1[i]==s2[j])
               prev=j;
               next[i+1][j+1]=prev;
            
        }
    }
    for(i=1;i<=m;i++){
        dp[i][0]=1;
    }
    for(j=1;j<=n;j++)
    {
        dp[0][i]=MAX;
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++)
        {
            if(next[i][j]==-1){
                dp[i][j]=1;
            }
            else{
                int a=dp[i-1][j];
                int b=dp[i-1][next[i][j]]+1;
                dp[i][j]=min(a,b);
                
            }
        }
    }
    
    
    return dp[m][n];
    
    
}
int main()
{ 
 string s1,s2;
 cin>>s1>>s2;
 cout<<shortestSeq(s1,s2)<<endl;
 return 0;
 }
