// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

int n,m,a[1000005];
struct node{int val,id;}b[1000005];
int ind(int i,int j){return (i-1)*m+j;}
int cmp(node a,node b){return a.val < b.val;}
void solve(){
	int sum = 0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int le = 0;
		for(int j=1;j<=m;j++){
			scanf("%d",&a[ind(i,j)]);
			if(a[ind(i,j)] == 1)++ le;
		}
		b[i]=node{le,i};
		sum += le;
	}
	if(sum % n)return (void)puts("-1");

	sum /= n;
	int s = sum;
	sort(b+1,b+n+1,cmp);
	int l=1,r=n;
	vector<pair<pii,int>>vc; 
	while(l < r){
		int nl = b[l].id, nr = b[r].id;
		int i=1,j=1;
		while(b[l].val < s && b[r].val > s){
			if(a[ind(nl,i)] == 0 && a[ind(nr,i)] == 1){
				++ b[l].val;
				-- b[r].val;
				vc.push_back(mpr(mpr(nl,nr),i));
				a[ind(nl,i)]=1,a[ind(nr,i)]=0;
			}
			++ i;
		}
		if(b[l].val == s)++ l;
		if(b[r].val == s)-- r;
	}
	printf("%d\n",vc.size());
	for(pair<pii,int>u:vc)printf("%d %d %d\n",u.first.first,u.first.second,u.second);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

