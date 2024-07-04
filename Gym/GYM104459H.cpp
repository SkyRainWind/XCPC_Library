// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int n;
struct node{int l,r;}a[maxn];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+n+1,[&](node a,node b){return a.l<b.l;});
	priority_queue<int,vector<int>,greater<int> >pq;
	int x=0,idx=1,ans=0;
	for(;;){
		while(!pq.empty() && pq.top() < x)pq.pop();
		if(pq.empty()){
			if(idx > n)break;
			x=a[idx].l;
		}else{
			++ ans;
			pq.pop();
			++x;
		}
		while(idx<=n&&a[idx].l<=x){
			pq.push(a[idx].r);++idx;
		}
	}
	printf("%d\n",ans);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

