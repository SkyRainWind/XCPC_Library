// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = 105;

int n,m,k;
struct stu{
	LL a,b;
	int c,d,id;
}a[maxn];
int cmp(stu a,stu b){return a.c <= b.c;}
LL dp[55][55][105];
struct node{int a,b,c;}lstdp[55][55][105];

void ckmx(LL &p,LL q){p = max(p, q);}

signed main(){
//	freopen("51nod1636.in","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%I64d%I64d%d",&a[i].a,&a[i].b,&a[i].c), a[i].d = a[i]. b - a[i].a, a[i].id =i;
	if(n == 1){
		LL ans = 0,id;
		for(int i=1;i<=m;i++)ans=max(ans,a[i].b), ans == a[i].b ? id =i : 1;
		printf("YES\n%I64d %I64d\n",id,ans);
		return 0;
	}
	
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m-1;i++)
		for(int j=0;j<=a[i].d;j++)
			dp[1][i][j] = a[i].a + j;
	
	for(int i=2;i<=n;i++){
		for(int lst=i-1;lst<=m-1;lst++){
			for(int delt = 0;delt <= a[lst].d;delt++)if(dp[i-1][lst][delt]){
				for(int now = lst + 1;now <= m; now++)if(a[now].c > a[lst].c){
					LL lsth = a[lst].a + delt;
					if(lsth + k <= a[now].b && lsth + k >= a[now].a){
						LL &d1 = dp[i][now][lsth + k - a[now].a];
						LL d2 = dp[i-1][lst][delt] + lsth + k;
						if(d1 < d2)
							d1 = d2, lstdp[i][now][lsth + k - a[now].a] = node{lst, delt, a[lst].id};
					}
					
					if(lsth * k <= a[now].b && lsth * k >= a[now].a){
						LL &d1 = dp[i][now][lsth * k - a[now].a];
						LL d2 = dp[i-1][lst][delt] + lsth * k;
						if(d1 < d2)
							d1 = d2, lstdp[i][now][lsth * k - a[now].a] = node{lst, delt, a[lst].id};
					}
				}
			}
		}
	}
	LL ans = -1; 
	node fst;
	vector<pair<int,LL> >res;
	for(int i=n;i<=m;i++)
		for(int j = 0; j <= a[i].d; j++)
			if(dp[n][i][j] && ans < dp[n][i][j])
				ans = dp[n][i][j], fst = node{i, j, a[i].id};
	if(ans == -1)puts("NO");
	else{
		puts("YES");
		for(int i=n;i>=1;i--){
			res.push_back(mpr(fst.c, fst.b + a[fst.a].a));
			fst = lstdp[i][fst.a][fst.b];
		}
		reverse(res.begin(),res.end());
		for(pair<int,LL> u : res)printf("%d %I64d\n",u.first,u.second);
	}

	return 0;
}

