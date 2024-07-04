// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,m;
pii a[maxn], b[maxn];

signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].first),a[i].second = i;
	for(int i=1;i<=m;i++)scanf("%d",&b[i].first),b[i].second = i;
	
	sort(a+1,a+n+1,[&](pii a,pii b){return a.first>b.first;});
	sort(b+1,b+m+1,[&](pii a,pii b){return a.first>b.first;});
	
	bitset<150002>now,ans;
	for(int i=1;i<=n;i++)ans[i] = 1;
	for(int i=1,j=0;i<=m;i++){
		int lst = j;
		while(lst < n && a[lst+1].first >= b[i].first){
			now[a[lst+1].second] = 1;
//			printf("! %d\n",a[lst+1].second);
			++ lst;
		}
//		debug();
		ans &= now >> (b[i].second-1);
		j = lst;
	}
	printf("%d\n",ans.count());

	return 0;
}

