#include<bits/stdc++.h>
using namespace std;
int dp[20];
int F(int n)
{
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    else{
        dp[n] = F(n-1) + F(n-2);
        return dp[n];
    }
}
int main()
{

    int n;
    cin >> n;
    memset(dp,-1,sizeof(dp));
    cout <<n << "th Fibo num  is = " << F(n) <<endl;
}
