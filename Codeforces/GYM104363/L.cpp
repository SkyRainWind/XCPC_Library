// by SkyRainWind
// O(n^2) 暴力凭什么过
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 2e5+5;

int n,k;
int a[maxn], c[maxn], b[maxn];
struct que{
	int l,r,id;
};
que q[maxn];

signed main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), c[i] = c[i-1] ^ a[i];
	int qu;scanf("%d",&qu);
	for(int i=1;i<=qu;i++)
		scanf("%d%d",&q[i].l,&q[i].r), q[i].id = i;
	sort(q+1,q+qu+1,[&](que a,que b){
		return a.r < b.r;
	});

	vector<int>ans(n + 1);
	int now = 1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if((c[j-1] ^ c[i]) <= k){
				b[j] = max(b[j], i-j+1);
			}
			if(j < i)b[j] = max(b[j], b[j+1]);
		}

		while(now <= qu && q[now].r == i){
			ans[q[now].id] = b[q[now].l];
			++ now;
		}
	}
	for(int i=1;i<=qu;i++)
		printf("%d\n",ans[i]);

	return 0;
}