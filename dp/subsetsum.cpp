#include <iostream>

using namespace std;

//subset sum is very similar to knapsack
//there is no val[] array, so, ignore it.

int subsetsum(int arr[], int sum, int n){
	//initialized dp table
	bool dp[n+1][sum+1];
	//fill up the dp table's first row and column
	for(int i=0; i<n+1; i++){
		for(int j=0; j<sum+1; j++){
			if(i==0)
				dp[i][j]=0;
			if(j==0)
				dp[i][j]=1;
		}
	}

	//process the values
	for(int i=1; i<n+1; i++){
		for(int j=1; j<sum+1; j++){
			if(arr[i-1] <= j){
				dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	return dp[n][sum];
}

int main(){

	int n = 5;
	int arr[5] = {2,3,7,8,10};
	int sum = 11;

	cout << subsetsum(arr, sum, n) << "\n";

	return 0;
}