#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
int T,cas;
ll L,R,K,f[20][(1 << 10) + 1][11],num[20];

ll calc(ll S,ll &k,ll x)
{
    int cur = -1;
    for (ll i = x; i <= 9; i++)
        if (S & (1 << i))
        {
            cur = i;
            break;
        }
    if (cur == -1)
    {
        k++;
        S |= (1 << x);
    }
    else
    {
        S ^= (1 << cur);
        S |= (1 << x);
    }
    return S;
}
int ppp=0;
ll dfs(ll len,ll S,ll k,bool limit,bool flag)
{
	++ppp; 
    if (!len)
        return k == K;
    if (!limit && f[len][S][K] != -1)
        return f[len][S][K];
    ll maxx = (limit ? num[len] : 9),cnt = 0;
    for (ll i = 0; i <= maxx; i++)
    {
        ll tempk = k,tempS;
        if (!i && flag)
            tempS = 0;
        else
            tempS = calc(S,tempk,i);
        cnt += dfs(len - 1,tempS,tempk,i == maxx && limit,flag && !i);
    }
    if (!limit)
        return f[len][S][K] = cnt;
    return cnt;
}

ll solve(ll x)
{
    ll len = 0;
    while (x)
    {
        num[++len] = x % 10;
        x /= 10;
    }
    return dfs(len,0,0,1,1);
}

int main()
{
	freopen("HDU4352.in","r",stdin);
	freopen("HDU4352_2.out","w",stdout);
    memset(f,-1,sizeof(f));
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lld%lld%lld",&L,&R,&K);
        printf("Case #%d: %lld\n",++cas,solve(R) - solve(L - 1));
    }

    return 0;
}
