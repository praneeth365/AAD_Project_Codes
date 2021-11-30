#include<bits/stdc++.h>
using namespace std;

int count( vector<int>& coins, int n ) 
{ 

    int length= coins.size();
    vector<int> dp(n+1,0); 
    dp[0] = 1; 
    for(int i=0; i<length; i++) 
        for(int j=coins[i]; j<=n; j++) 
            dp[j] += dp[j-coins[i]]; 

    return dp[n]; 
} 

    
int main()
{
    int amount = 50;
    vector<int> arr={1,2,5};
    cout<<count(arr,5);
     return 0;
}
