// unAC
// by Balloons
#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

vector< pair<int,pair<int,int> > >a[maxn];
int n,m,k;
int ans[maxn];
queue<int>Q;

pair<int,pair<int,int> >tr(int p,int q,int r){return mpr(p,mpr(q,r));}

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		int p1,q1,p2,q2;scanf("%d%d%d%d",&p1,&q1,&p2,&q2);
		a[p1].push_back(tr(q1-1,p2,q2-1));
		a[p1].push_back(tr(q1,p2,q2));
		a[p2].push_back(tr(q2-1,p1,q1-1));
		a[p2].push_back(tr(q2,p1,q1));
	}
	for(int i=1;i<=n;i++)sort(a[i].begin(),a[i].end());
	for(int i=1;i<=n;i++)ans[i]=1, Q.push(i);
	while(!Q.empty()){
		int u = Q.front();Q.pop();
		printf("! %d\n",u);
		for(auto i : a[u]){
			#define s1 (i.first)
			#define s2 (i.second.first)
			#define s3 (i.second.second)
			if(ans[u] < s1)break;
			ans[s2] = max(ans[s2], s3);
			Q.push(s2);
		}
	}
	LL res=0;
	for(int i=1;i<=n;i++){
		if(ans[i] > m)return puts("-1"),0;
		res += ans[i];
	}
	printf("%lld\n",res);
	

	return 0;
}


