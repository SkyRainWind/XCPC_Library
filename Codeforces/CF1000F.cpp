// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 5e5+5;

int n,a[maxn],qu;
int bel[maxn], ed[maxn];
struct que{int l,r,id;}q[maxn];
int cnt[maxn], sum[maxn];

void del(int x){
	if(cnt[a[x]] == 2)++ sum[bel[a[x]]];
	if(cnt[a[x]] == 1)-- sum[bel[a[x]]];
	-- cnt[a[x]];
}

void add(int x){
	if(cnt[a[x]] == 0)++ sum[bel[a[x]]];
	if(cnt[a[x]] == 1)-- sum[bel[a[x]]];
//	printf("? %d %d %d\n",cnt[a[x]],x,sum[bel[a[x]]]);
	++ cnt[a[x]];
}

int getans(){
	for(int i=bel[500000];i;i--){
		if(!sum[i])continue;
		for(int j=(i-1)*1000;j<=i*1000-1;j++){
//			printf("%d %d -- \n",j,cnt[j]);
			if(cnt[j] == 1)return j;
		}
	}
	return 0;
}

signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1,blk=1000;i<=maxn-5;i++)
		bel[i] = i / blk + 1,
		ed[i] = bel[i];
		
	int qu;scanf("%d",&qu);
	for(int i=1;i<=qu;i++)scanf("%d%d",&q[i].l,&q[i].r),q[i].id = i;
	sort(q+1,q+qu+1,[&](que a,que b){
		return bel[a.l] != bel[b.l] ? a.l < b.l : (bel[a.l]%2==1 ? a.r < b.r : a.r > b.r);
	});
//	for(int i=1;i<=qu;i++)printf("%d %d\n",q[i].l,q[i].r);
	int nowl=0, nowr=0;
	
	vector<int>ans(qu + 2);
	for(int i=1;i<=qu;i++){
		while(nowl < q[i].l)del(nowl ++);
		while(nowl > q[i].l)add(-- nowl);
		while(nowr < q[i].r)add(++ nowr);
		while(nowr > q[i].r)del(nowr --);
		ans[q[i].id] = getans();
//		printf("> %d %d\n",q[i].l,q[i].r);
//		printf("%d %d %d %d\n",cnt[2],cnt[3],cnt[4],sum[1]);
	}
	for(int i=1;i<=qu;i++)printf("%d\n",ans[i]);

	return 0;
}

