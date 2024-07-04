// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n,m;
vector<int>ed[31][maxn],g[31][maxn];
int vis[31][maxn],a[maxn];

inline int read(int x=0,int f=1){
    char ch=getchar();
    while(ch<'0'||ch>'9')f=(ch=='-'?-1:1),ch=getchar();
    while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return x*f;
}

signed main(){
	memset(vis,-1,sizeof vis);
	n=read(),m=read();
	while(m --){
		int u=read(),v=read(),w=read();
		if(u > v)swap(u,v);
		for(int i=0;i<=29;i++){
			if(w&(1<<i)){
				ed[i][v].push_back(u); 
				g[i][u].push_back(v);
			}else{
				vis[i][u] = vis[i][v] = 0;
			}
		}
	}
	for(int d=0;d<=29;d++)
		for(int i=1;i<=n;i++)
			for(auto j : ed[d][i]){
				if(vis[d][i] == 0)vis[d][j] = 1;
				if(vis[d][j] == 0)vis[d][i] = 1;
			}
	
	for(int i=1;i<=n;i++){
		for(int d=29;d>=0;d--){
			if(~vis[d][i]){
				a[i] |= (vis[d][i]<<d); 
			}else{
				for(auto j : g[d][i]){
					vis[d][j] = 1;
					a[j] |= (1<<d);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");

	return 0;
}


