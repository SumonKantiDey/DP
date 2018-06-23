///http://www.shafaetsplanet.com/planetcoding/?p=1158
#include<bits/stdc++.h>
using namespace std;
int coin[] = {1,5,10,25,50};///value of is available here we can take a coin many times
int make;
int dp[6][10000];

int CoinChange(int i, int amount)
{
    if(i >= 5)//All coins have been taken
    {
        if(amount  == 0) return 1;
        else return 0;
    }

    if(dp[i][amount] != -1) return dp[i][amount];

    int ret1 = 0, ret2 = 0;
    if(amount - coin[i] >=0 ) ret1 = CoinChange(i,amount - coin[i]);///try to take coin i

    ret2 = CoinChange(i + 1,amount);///Do not take coin i

    return dp[i][amount] = ret1 + ret2;///storing and returning
    ///return dp[i][amount] = ret1 | ret2;///this statement show that is it possible to make this value
                                           ///with this coin
}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(cin >> make)
    {
        cout << "For making " << make <<  " total ways are : " <<CoinChange(0,make) <<endl;
    }
    return 0;
}

