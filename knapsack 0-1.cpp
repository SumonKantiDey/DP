#include<bits/stdc++.h>
using namespace std;
#define MX 1005
int dp[MX][MX];
bool dir[MX][MX];
int weight[MX];
int cost[MX];
int CAP,n;
int fun(int i,int w)
{
    if(i == n+1) return 0; //সব কিছু নেয়া হয়ে গেছে
    if(dp[i][w] != -1) return dp[i][w]; //এই  স্টেট আগে হিসাব করে এসেছি
    int profit1,profit2;
     profit1 = profit2 = 0;

    if((w+weight[i] <= CAP))
    {
        profit1 = cost[i] + fun(i+1,w + weight[i]);//যদি i তম জিনিস টা নিয়ে থাকি তাইলে লাভ
    }
    profit2 = fun(i+1,w);//যদি iতম জিনিস টা না নিয়ে থাকি তাইলে লাভ

    dir[i][w] = profit1 > profit2;//এই খানে আমি কোন স্টেট  নিলে  dir valu ১  নাহলে ০ সেট হবে w এর মান আগের ওয়েট এর সাথে যোগ হয়ে আসছে
    return dp[i][w] = max(profit1,profit2);
}

void path()
{
    vector<int> v;
    for(int i = 1,j=0; i <= n; i++)
    {

        if(dir[i][j])
        {
            v.push_back(i);
            j = j + weight[i];

        }
    }
    cout << "Total taken " << v.size() <<endl;
    for(int i = 0; i<v.size(); i++)
    {
        cout << weight[v[i]] << " " << cost[v[i]] <<endl;
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n >> CAP;
    for(int i = 1; i<=n; i++)
    {
        cin >> weight[i] >> cost[i];
    }
    cout << fun(1,0)<<endl;
    path();
}


/**
4 10///4 state and  size of bag is 10
3 100
2 350
2 120
8 280
**/
