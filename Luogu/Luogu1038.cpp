// by SkyRainWind
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=105;
int n,p,c[maxn],u[maxn];
vector<pair<int,int> >g[maxn];
int seq[maxn], se=0, vis[maxn], out[maxn], ou, cur[maxn];
signed main(){
	scanf("%d%d",&n,&p);
	queue<int>Q;
	for(int i=1;i<=n;i++){	
		scanf("%d%d",&c[i],&u[i]);
		cur[i] = c[i];
		if(c[i])Q.push(i);
	}
	for(int i=1;i<=p;i++){
		int x,y,w;scanf("%d%d%d",&x,&y,&w);
		g[x].push_back(mpr(y, w));
	}
	while(!Q.empty()){
		int fr = Q.front();Q.pop();
		vis[fr] = 1;
		seq[++ se] = fr;
		for(pii v : g[fr]){
			if(!vis[v.first])Q.push(v.first), vis[v.first] = 1;
		}
	}
	for(int i=1;i<=n;i++)
		if(g[i].size() == 0)out[++ ou] = i;
		
	for(int i=1;i<=se;i++){
		int cc = seq[i];
		if(!c[cc]){
			cur[cc] -= u[cc];
			if(cur[cc] <= 0)cur[cc] = 0;
		}
		for(pii fr : g[cc]){
			cur[fr.first] += fr.second * cur[cc];
		}
	}
	int fg = 1;
	for(int i=1;i<=ou;i++)
		if(cur[out[i]])printf("%d %d\n",out[i], cur[out[i]]), fg = 0;
	if(fg)puts("NULL");

	return 0;
}


