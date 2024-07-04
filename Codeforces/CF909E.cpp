// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 500005;

int n,m,a[maxn];
queue<int>Q, qmain;
vector<int>g[maxn];
int de[maxn],out[maxn];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&y,&x);++x, ++y;
		g[x].push_back(y);
		++ de[y];++ out[x];
	}
	
	int ans = 0;
	for(int i=1;i<=n;i++){
		if(!de[i] && !a[i]){
			qmain.push(i);
		}
	}
	
	for(int i=1;i<=n;i++){
		if(!de[i] && a[i])
			Q.push(i);
	}
	
	while(!Q.empty() || !qmain.empty()){
		while(!qmain.empty()){
			int u = qmain.front();qmain.pop();
			for(int v : g[u])
				if(!--de[v]){
					if(!a[v])qmain.push(v);
					else Q.push(v);
				}
		}
		
		if(Q.empty())break;
		++ ans;
		while(!Q.empty()){
			int fr = Q.front();Q.pop();
			for(int u : g[fr]){
				if(!--de[u]){
					if(!a[u]){
						qmain.push(u);
					}else Q.push(u);
				}
			}
		}
	}
	printf("%d\n",ans);

	return 0;
}
