// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

void solve(){
	int x,t,k,n,d;
	scanf("%d%d%d%d%d",&x,&t,&k,&n,&d);
	vector<int>a(n+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int cu=x,ts=0;
	for(int i=1;i<=2*n;i++){
		int c=a[i > n ? i-n : i];
		if(c<=d){
			cu--;
			if(cu<=k)++ts;
			else ts=0;
		}else{
			cu++;
			if(cu<=k)++ts;
			else ts=0;
		}
		if(ts>=t){
			puts("YES");
			return ;
		}
	}
	if(ts == 2*n){
		puts("YES");
		return ;
	}
	if(cu < x)puts("YES");
	else puts("NO");
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

