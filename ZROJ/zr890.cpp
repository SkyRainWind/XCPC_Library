// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 1e6 +5;

char s[maxn], mp[maxn];
int tr[maxn][28], n;
int res[maxn], fa[maxn];

signed main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int now = 0, totr = 0;
	LL ans = 0;
	for(int i=1;i<=n;i++){
		int cc = s[i] - 'a';
//		printf("%d %c %c\n",i,mp[now],s[i]);
		if(mp[now] == s[i]){now = fa[now];ans += ++res[now];continue;}
		if(tr[now][cc]){now = tr[now][cc];ans += ++res[now];continue;}
		if(!tr[now][cc])tr[now][cc] = ++totr, mp[totr] = s[i];
		fa[tr[now][cc]] = now;
//		printf("%d %d\n",now,tr[now][cc]);
		now = tr[now][cc];
	}
	printf("%lld\n",ans);

	return 0;
}


