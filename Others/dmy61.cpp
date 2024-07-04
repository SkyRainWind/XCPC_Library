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

int n;ll k;
int a[200005];
int check(ll lim){
	ll s=0;
	for(int i=1;i<=n;i++)if(a[i]<lim){
		s+=lim-a[i];
		if(s>k)return 0;
	}
	return s<=k;
}
signed main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	ll l=1,r=1e15,ans;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1; 
	}
	cout<<ans;

	return 0;
}

