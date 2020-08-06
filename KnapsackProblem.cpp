A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. 
What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry

Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13
___________________________________________________________________________________________________________________________________________________________________________________
Solution:
#include<iostream>
#include<cmath>
using namespace std;
int knapsack(int* weights, int* values, int n, int maxWeight){
int* arr1=new int[maxWeight+1];
    int* arr2=new int[maxWeight+1];
    for(int i=0;i<maxWeight+1;i++)
    {
        arr1[i]=0;
        arr2[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=maxWeight;j++)
        {
            if(j-weights[i-1]>=0)
            {
                arr2[j] = max(arr1[j], values[i - 1] + arr1[j - weights[i - 1]]);
            }
            else
            {
                arr2[j]=arr1[j];
            }
        }
        for(int j=0;j<=maxWeight;j++)
        {
            arr1[j]=arr2[j];
            arr2[j]=0;
        }
    }
     	return arr1[maxWeight];
  }
  int main(){

  int n; 
  cin >> n;
  int* weights = new int[n];
  int* values = new int[n];

  for(int i = 0; i < n; i++){
    cin >> weights[i];
  }

  for(int i = 0; i < n; i++){
    cin >> values[i];
  }

  int maxWeight;
  cin >> maxWeight;

  cout << knapsack(weights, values, n, maxWeight);

}



     	
