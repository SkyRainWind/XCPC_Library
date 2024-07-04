// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=4e6+5;

namespace ntt{
	const int mod=998244353,mod_g=3,g_inv=332748118;
		
	int pw(int x,int y){
		if(y==0)return 1;
		if(y==1)return x;
		int mid=pw(x,y>>1);
		if(y&1)return 1ll*mid*mid%mod*x%mod;
		return 1ll*mid*mid%mod; 
	}
	
	ll a[maxn],b[maxn];
	int r[maxn],lim;
	
	void dft(ll *a,int op){
		for(int i=0;i<lim;i++)if(i<r[i])swap(a[i],a[r[i]]);
		for(int mid=1;mid<lim;mid<<=1){
			ll wn = pw(op==1?mod_g:g_inv,(mod-1)/(mid<<1));
			for(int r=mid<<1,j=0;j<lim;j+=r){
				ll w=1;
				for(int k=0;k<mid;k++,w=w*wn){
					ll x=a[j+k],y=w*a[j+mid+k]%mod;
					a[j+k]=(x+y)%mod;
					a[j+mid+k]=(x-y+mod)%mod;
				}
			}
		}
	}
	
	vector<int>ntt(vector<int>f,vector<int>g){	// f[0] g[0] ´ú±íµÍÎ»  
		int n=f.size(),m=g.size();
		--n, --m;
		int len=0;
		lim=1;
		while(lim<=n+m)lim<<=1,++len;
		for(int i=0;i<=lim;i++)r[i]=(r[i>>1]>>1)|((i&1)<<(len-1));
		for(int i=0;i<=n;i++)a[i]=f[i];
		for(int i=0;i<=m;i++)b[i]=g[i];
		
		dft(a,1);dft(b,1);
		for(int i=0;i<=lim;i++)a[i]=a[i]*b[i]%mod;
		dft(a,-1);
		
		vector<int>res;
		int inv = pw(lim,mod-2);
		for(int i=0;i<=n+m;i++)res.pb(a[i]*1ll*inv%mod);
		return res;
	}
}

vector<int>f,g;
signed main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0,x;i<=n;i++)scanf("%d",&x),f.pb(x);
	for(int i=0,x;i<=m;i++)scanf("%d",&x),g.pb(x);
	
	vector<int>res = ntt::ntt(f,g);
	for(int i=0;i<res.size();i++)printf("%d ",res[i]);

	return 0;
}

