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

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=50000 * 27 + 5;

int n,m;
int tr[500005][28];
int go[maxn], cur[maxn], fa[maxn];
char s[maxn];
int totr = 0;

int update(){
	scanf("%s", s + 1);
	int len = strlen(s +1);
	if(s[len] != '/')s[++len] = '/';
	int now = 0;
	for(int i=1;i<=len;i++){
		int cc = s[i] - 'a';
		if(i == len){
			now = go[now];
			continue;
		}
		if(s[i] == '/'){
			now = go[now];
			cc = 26;
		}
		if(!tr[now][cc]){
			tr[now][cc] = ++totr;
			go[totr] = totr;
			fa[totr] = now;
			cur[totr] = s[i];
		}
		now = tr[now][cc];
	}
	return now;
}

char tt[maxn];
int cc = 0;
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int fx = update(), fy = update();
		go[fx] = fy;
	}
	while(m --){
		int ff = update();
		cc = 0;
		for(int i = ff;i;i=fa[i])tt[++ cc] = cur[i];
		if(cc == 0)tt[++ cc] = '/';
		for(int i=cc;i>=1;i--)putchar(tt[i]);puts("");
	}

	return 0;
}


