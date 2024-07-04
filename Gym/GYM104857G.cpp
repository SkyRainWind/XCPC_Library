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

int n,m,k;
char s[maxn];
int a[maxn];
int f[maxn][7][2], ze[maxn];

int get(int l,int r){
	return ze[r] - ze[l-1];
}

int check(int x){
	for(int i=0;i<=n;i++)
		for(int j=0;j<=k;j++)f[i][j][0] = f[i][j][1] = inf;
	f[0][0][0] = 0;
	int t = inf;
	for(int i=1;i<=n;i++){
		if(a[i] == 0)f[i][0][0] = 0;
		for(int j=0;j<=k;j++){
			if(i >= x && j && a[i-x] == 0)f[i][j][1] = f[i-x][j-1][0] + get(i-x+1, i);
			f[i][j][0] = min(f[i-1][j][0], f[i-1][j][1]);
			t = min(t, min(f[i][k][0], f[i][k][1]));
		}
	}
	return t <= m;
}

signed main(){
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i] = s[i] - '0';
	for(int i=1;i<=n;i++){
		ze[i] = ze[i-1];
		if(a[i] == 0)++ ze[i];
	}
	
//	printf("%d\n",check(2));
	int l=1, r=n, ans = -1;
	while(l <= r){
		int mid = l+r>>1;
		if(check(mid))l = mid+1,ans = mid;
		else r=mid-1;
	}
	printf("%d\n",ans);

	return 0;
}

