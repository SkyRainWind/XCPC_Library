// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn = (1<<17)+5,mod=998244353;

int n;
vector<int>a,b;

namespace fwt{
	vector<int>fwtand(vector<int>a,int op){
		for(int len=2,k=1;len<=(1<<n);len<<=1,k<<=1){
			for(int i=0;i<(1<<n);i+=len)
				for(int j=0;j<k;j++)
					a[i+j]+=(1ll*a[i+j+k]*op%mod+mod)%mod,
					a[i+j]%=mod;
		}
		return a;
	}
	vector<int>fwtand(vector<int>a,vector<int>b){
		a = fwtand(a,1);b = fwtand(b,1);
		for(int i=0;i<(1<<n);i++)a[i]=1ll*a[i]*b[i]%mod;
		a = fwtand(a,mod-1);
		return a;
	}
	
	vector<int>fwtor(vector<int>a,int op){
		for(int len=2,k=1;len<=(1<<n);len<<=1,k<<=1){
			for(int i=0;i<(1<<n);i+=len)
				for(int j=0;j<k;j++)
					a[i+j+k]+=(1ll*a[i+j]*op%mod+mod)%mod,
					a[i+j+k]%=mod;
		}
		return a;
	}
	vector<int>fwtor(vector<int>a,vector<int>b){
		a = fwtor(a,1);b = fwtor(b,1);
		for(int i=0;i<(1<<n);i++)a[i]=1ll*a[i]*b[i]%mod;
		a = fwtor(a,mod-1);
		return a;
	}

	vector<int>fwtxor(vector<int>a,int op){
		for(int len=2,k=1;len<=(1<<n);len<<=1,k<<=1){
			for(int i=0;i<(1<<n);i+=len)
				for(int j=0;j<k;j++){
					(a[i+j]+=a[i+j+k])%=mod,
					(a[i+j+k]=((a[i+j]-2ll*a[i+j+k]%mod)%mod+mod)%mod) %= mod,
					a[i+j]=1ll*a[i+j]*op%mod, a[i+j+k]=1ll*a[i+j+k]*op%mod;
				}
		}
		return a;
	}
	vector<int>fwtxor(vector<int>a,vector<int>b){
		a = fwtxor(a,1);b = fwtxor(b,1);
		for(int i=0;i<(1<<n);i++)a[i]=1ll*a[i]*b[i]%mod;
		a = fwtxor(a,(mod+1)/2);	// 1/2 = inv(2) = (mod+1)/2
		return a;
	}
}

signed main(){
	scanf("%d",&n);
	for(int i=0,x;i<(1<<n);i++)scanf("%d",&x),a.pb(x);
	for(int i=0,x;i<(1<<n);i++)scanf("%d",&x),b.pb(x);
	vector<int>c=a,d=b; 
	vector<int>res;
	res = fwt::fwtor(a,b);
	for(int it:res)printf("%d ",it);puts("");
	res = fwt::fwtand(a,b);
	for(int it:res)printf("%d ",it);puts("");
	res = fwt::fwtxor(a,b);
	for(int it:res)printf("%d ",it);puts("");

	return 0;
}
