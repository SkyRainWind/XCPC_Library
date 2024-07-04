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

int n,a[maxn];
ll sum=0;

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]), sum+=a[i];
	int r=0,lst=0;
	for(int j=1;j<=12;j++){
		int s=lst;
		for(int i=1;i<=n;i++){
			s += a[i]%10;
			a[i] /= 10;
		}
		if(s>=10)r += s/10, lst = s/10;
	}
	printf("%d\n",r);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

