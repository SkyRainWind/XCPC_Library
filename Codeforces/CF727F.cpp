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

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n,m,a[maxn];
priority_queue<LL>pq;
LL sum[maxn], nn;

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		if(a[i] < 0)pq.push(a[i]);
		else{
			while(!pq.empty() && a[i] >= 0){
				a[i] += pq.top();
				pq.pop();
			}
			if(a[i] < 0)pq.push(a[i]);
		}
	}
	while(!pq.empty()){
		sum[++ nn] = -pq.top(); pq.pop();
	}
	for(int i=1;i<=nn;i++)sum[i] += sum[i-1];
	while(m --){
		LL t;scanf("%lld",&t);
		if(sum[nn] <= t)puts("0");
		else{
			int id = upper_bound(sum+1, sum+nn+1, t) - sum - 1;
			printf("%d\n",nn - id);
		}
	}

	return 0;
}

