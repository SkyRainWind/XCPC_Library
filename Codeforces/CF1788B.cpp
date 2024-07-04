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
	char s[109];
	scanf("%s",s+1);
	int n=strlen(s+1);
	int base = 1;
	int a1=0,a2=0;
	int st = 1;
	for(int i=n;i>=1;i--){
		int cc = s[i]-'0';
		if((s[i]-'0')&1){
			cc /= 2;
			a1 += base*cc, a2 += base*cc;
			if(st)a1 += base;
			else a2 += base;
			st ^= 1;
		}else{
			cc /= 2;
			a1 += base * cc;
			a2 += base * cc;
		}
		base *= 10;
	}
	printf("%d %d\n",a1,a2);
}

signed main(){
	int te;scanf("%d",&te);
	while(te--)solve();

	return 0;
}

