// by SkyRainWind
#include <cstdio>
#include <vector>
#include <queue>
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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=105;

int n,h,f[maxn],d[maxn],t[maxn];
struct node{int val,id;node(int val,int id):val(val),id(id){}};
bool operator < (node a, node b){return a.val < b.val;}
priority_queue<node>pq,pq2;

signed main(){
//	freopen("1717.in","r",stdin);
	scanf("%d%d",&n,&h);
	h *= 12;
	for(int i=1;i<=n;i++)scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	for(int i=2;i<=n;i++)scanf("%d",&t[i]);
	int cur = 0, ans = 0, pref = 0;
	for(int i=1;i<=n;i++){
		pref += f[i];
		if(f[i] >= d[i])pq2.push(node(f[i]-d[i],i));
		if(i>=2)cur += t[i];
		cur ++;
		int cur2 = cur;
		if(cur > h)break;
		int res = pref;
		pq = pq2;
//		debug();
		while(!pq.empty()){
			node tp = pq.top();pq.pop();
			++ cur2;
			if(cur2 > h)break;
//			printf("~ %d\n",tp.val);
			res += tp.val;
			if(tp.val - d[tp.id] > 0)pq.push(node(tp.val - d[tp.id], tp.id));
		}
		
		ans = max(ans, res);
	}
	printf("%d\n",ans);

	return 0;
}

