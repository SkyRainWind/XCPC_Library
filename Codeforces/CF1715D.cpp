// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
 
using namespace std;
 
typedef long long LL;
 
const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;
 
int n,q;
struct node{int i,j,x;}a[maxn];
int b[maxn];
int vis[maxn];
set<int>S[maxn];
 
int cmp(node a,node b){return a.i == b.i ? a.j < b.j : a.i < b.i;}
 
signed main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d%d",&a[i].i,&a[i].j,&a[i].x);
		if(a[i].i >a[i].j) swap(a[i].i,a[i].j);
	}
	for(int p=0;p<=29;p++){
		memset(vis,0,sizeof vis);
		int cur = 1<<p;
//		for(int i=1;i<=q;i++)if(a[i].i == a[i].j)b[a[i].i] |= (a[i].x&cur)?cur:0, vis[a[i].i] = 1;
		for(int i=1;i<=q;i++){
			if((a[i].x & cur) == 0){
				vis[a[i].i] = vis[a[i].j] = 1;
			}
		}
		for(int i=1;i<=q;i++){
			if(a[i].x & cur){
				if(vis[a[i].i]==1||vis[a[i].j]==1){
					if(!vis[a[i].i])b[a[i].i] |= cur;
					if(!vis[a[i].j])b[a[i].j] |= cur;
					vis[a[i].i] = vis[a[i].j] = 1;
				}
			}
		}
		
		for(int i=1;i<=n;i++)S[i].clear();
		for(int i=1;i<=q;i++){if(!vis[a[i].i])S[a[i].i].insert(a[i].j);}
		for(int i=1;i<=n;i++)if(!vis[i]){
			vis[i] = 1;
			for(auto j : S[i]){
				b[j] |= cur;
				vis[j] = 1;
			}
		}
	}
	for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
 
	return 0;
}
