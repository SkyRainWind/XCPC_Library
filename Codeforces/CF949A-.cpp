// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

char s[maxn];
int n;
vector<int>ans[maxn];

signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	
	int zero = 1, mx = 1;
	for(int i=1;i<=n;i++){
		if(s[i] == '0')ans[zero ++].push_back(i);
		else{
			-- zero;
			if(zero == 0)return puts("-1"), 0;
			ans[zero].push_back(i);
		}
		mx = max(mx, zero);
	}
	if(mx != zero)return puts("-1"), 0;
	printf("%d\n",zero - 1);
	for(int i=1;i<zero;i++){
		printf("%d ",ans[i].size());
		for(int u : ans[i])printf("%d ",u);puts("");
	}

	return 0;
}

