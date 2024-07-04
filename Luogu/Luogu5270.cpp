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

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e5+5;

int n,t,q;
int a[maxn],len[maxn],r[maxn];
vector<int>e[maxn];
int all[maxn],cnt=0,bub[maxn];
int tmpans1[maxn];

signed main(){
//	freopen("5270.in","r",stdin);
	scanf("%d%d%d",&n,&t,&q);
	for(int i=1;i<=t;i++)scanf("%d",&a[i]), ++ bub[a[i]];
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
		for(int j=1;j<=len[i];j++){
			int t;scanf("%d",&t);
			e[i].push_back(t);
		}
	}
	int m;scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&r[i]);
	int res1=0;
	for(int i=1;i<=m;i++){
		int buc[7];memset(buc,0,sizeof buc);
		int cur = r[i];
		for(auto j : e[cur])all[++ cnt] = j;
		for(int j=(cnt - t+1<=0?1:cnt-t+1);j<=cnt;j++)++ buc[all[j]];
		int fg = 1;
		for(int j = 0;j<=5;j++)fg &= (buc[j] == bub[j]);
		if(fg) ++ res1;
		if(i == q){
			printf("%d\n",res1);
			return 0;
		}
	}
	
	for(int i=1;i<=m;i++){
		tmpans1[i] = tmpans1[i-1];
		int buc[7];memset(buc,0,sizeof buc);
		int cur = r[i];
		for(auto j : e[(cur-1)%m+1])all[++ cnt] = j;
		for(int j=(cnt - t+1<=0?1:cnt-t+1);j<=cnt;j++)++ buc[all[j]];
		
		int fg = 1;
		for(int j = 0;j<=5;j++)fg &= (buc[j] == bub[j]);
		if(fg) ++ tmpans1[i];
		if(m + i == q){
			printf("%d\n",res1 + tmpans1[i]);
			return 0;
		}
	}
	printf("%d\n",res1 + tmpans1[m] * (q/m-1) + tmpans1[q%m]);

	return 0;
}


