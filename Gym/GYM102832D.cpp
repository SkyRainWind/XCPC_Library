// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, mod=1e9+7;

char s[3005];
int c;

int pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

signed main(){
	scanf("%s",s+1);
	scanf("%d",&c);
	int t=0,n=strlen(s+1),k=0,ans=0;
	for(int i=1;i<=n;i++)if(s[i]=='1')++k;
	ans = pw(c,k);
	for(int i=1;i<=n;i++)if(s[i]=='1'){
		(ans += 1ll*pw(c,t)*pw(1+c,n-i)%mod)%=mod;
		++t;
	}
	printf("%d\n",ans);

	return 0;
}

