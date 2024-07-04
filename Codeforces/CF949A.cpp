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
int tp1,tp2;
pii stk1[maxn], stk2[maxn];

signed main(){
	scanf("%s",s + 1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)stk1[++ tp1] = mpr(s[i] - '0',i);
	
	int all = 0;
	while(1){
		tp2 = 0;
		int cur = 0;
		int gg = 1;
		for(int i=1;i<=tp1;i++){
			stk2[++ tp2] = stk1[i];
			if(stk1[i].first == cur){
				gg = 0;
				-- tp2;
				cur ^= 1;
			}
		}
		if(cur == 0){
			puts("-1");
			return 0;
		}
		if(gg){
			puts("-1");
			return 0;
		}
		++ all;
		tp1 = tp2;
		int ok = 1;
		for(int i=1;i<=tp1;i++)stk1[i] = stk2[i], ok &= stk1[i].first == 0; 
		if(ok){
			all += tp1;
			break;
		}
	}
	
	tp1 = tp2 = 0;
	for(int i=1;i<=n;i++)stk1[++ tp1] = mpr(s[i] - '0',i);
	
	printf("%d\n",all);
	while(1){
		tp2 = 0;
		int cur = 0;
		vector<int>res; 
		for(int i=1;i<=tp1;i++){
			stk2[++ tp2] = stk1[i];
			if(stk1[i].first == cur){
				res.push_back(stk1[i].second);
				-- tp2;
				cur ^= 1;
			}
		}
		printf("%d ",res.size());
		for(int u : res)printf("%d ",u);puts("");
		tp1 = tp2;
		int ok = 1;
		for(int i=1;i<=tp1;i++)stk1[i] = stk2[i], ok &= stk1[i].first == 0; 
		if(ok){
			for(int i=1;i<=tp1;i++)printf("1 %d\n",stk1[i].second);
			break;
		}
	}

	return 0;
}

