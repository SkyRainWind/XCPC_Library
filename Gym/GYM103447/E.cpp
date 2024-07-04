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

int n,a[maxn];

void solve(){
	scanf("%d",&n);
	int fg=1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), fg &= (a[i]==0);
	if(fg){
		return puts("1"), void();
	}
	if(n <= 31){
		int f = 0;
		for(int i=2;i<=n;i++)
			if(a[i] == a[i-1]*2ll);
			else f=1;
		if(!f)return puts("-1"), void();
	}
	
	int pw = 1;
	int f=0;
	for(int i=1;i<=n;i++)
		if(a[i] == pw)pw *= 2;
		else{f=i;break;}
	int m = 2*a[f-1] - a[f];
	if(m == 0)return puts("-1"), void();
	int b = 1%m;
	for(int i=1;i<=n;i++){
		if(b != a[i])
			return puts("-1"), void();
		b = b * 2ll % m;
	}
	printf("%d\n",m);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

