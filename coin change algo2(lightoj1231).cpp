///http://www.shafaetsplanet.com/planetcoding/?p=1158
#include<bits/stdc++.h>
using namespace std;
#define MOD 100000007
int coin[51];
int times[55];
int make,n;
int dp[51][1005];

int CoinChange(int i, int amount)
{
   if(i >= n)//All coins have been taken
    {
        if(amount == 0) return 1;
        else return 0;
    }
    if(amount < 0) return 0;
    if(dp[i][amount] != -1) return dp[i][amount];

    int ret1 = 0, ret2 = 0;
    for(int j = 0; j <= times[i]; j++){
        if(amount - coin[i]*j >= 0 ) ret1 += CoinChange(i+1, amount - coin[i]*j)%MOD;///try to take coin i
    }

    //ret2 = CoinChange(i + 1,amount)%MOD;///Do not take coin i

    return dp[i][amount] = ret1;///storing and returning
}
int main()
{
    int t,cs = 0;
    cin >> t;
    while(t--)
    {
        cin >> n >> make;
        memset(dp,-1,sizeof(dp));
        for(int i = 0; i < n; i++) cin >> coin[i];
        for(int i = 0; i < n; i++) cin >> times[i];
        int res = CoinChange(0,make)%MOD;
        printf("Case %d: %d\n",++cs,res);
    }

    return 0;
}
