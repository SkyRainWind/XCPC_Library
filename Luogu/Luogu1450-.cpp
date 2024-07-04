#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define FR freopen("in.txt", "r", stdin)
#define FW freopen("out1.txt", "w", stdout)

#define MOD 1000000007

#define MAXT 100005

ll C[10];
ll D[10];

ll dp[MAXT];

int main()
{
    for (int i = 1; i <= 4; i++)
    {
        scanf("%lld", C + i);
    }

    dp[0] = 1;
    for (int i = 1; i <= 4; i++)
    {
        for (int w = C[i]; w < MAXT; w++)
        {
            dp[w] += dp[w - C[i]];
        }
    }

	cout << dp[100000] << '\n'; 
    int T;
    scanf("%d", &T);

    while (T--)
    {
        for (int i = 1; i <= 4; i++)
        {
            scanf("%lld", D + i);
        }
        ll S;
        scanf("%lld", &S);

        ll ans = 0;

        for (int b = 0; b <= 15; b++)
        {
            ll t = S;
            int cnt = 0;

            for (int i = 0; i <= 3; i++)
            {
                if ((b >> i) & 1)
                {
                    t -= C[i + 1] * (D[i + 1] + 1);
                    cnt = 1 - cnt;
                }
            }

            if(t < 0) continue;

            if (cnt)
            {
                ans -= dp[t];
            }
            else
            {
                ans += dp[t];
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}

