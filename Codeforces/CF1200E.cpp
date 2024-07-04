// by Balloons
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
 
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
 
const int inf = 1e9, INF = 0x3f3f3f3f;
const int p = 998244353,p2=19260817,maxn=1e5+5,mod=1e9+7; 
 
int n;
string s,ans;
int hs[1000005],hs2[1000005],bs[1000005],bs2[1000005];
int anshs[1000005],anshs2[1000005];
int cnt=0;
 
int gethash(int l,int r){
	int tmp = (hs[r] - 1ll*hs[l-1] * bs[r-l+1]%mod)%mod;
	tmp = (tmp+mod)%mod;
	return tmp;
}
 
int gethash2(int l,int r){
	int tmp = (hs2[r] - 1ll*hs2[l-1] * bs2[r-l+1]%mod)%mod;
	tmp = (tmp+mod)%mod;
	return tmp;
}
 
signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>s;
	ans = s;
	bs[0] = bs2[0] = 1;
	for(int i=1;i<=100000;i++)bs[i] = 1ll*bs[i-1] * p%mod;
	for(int i=1;i<=100000;i++)bs2[i] = 1ll*bs2[i-1] * p2%mod;
	
	cnt = s.size();
	for(int i=0;i<s.size();i++)anshs[i+1] = 1ll*anshs[i] * p%mod + s[i], anshs[i+1]%=mod;
	for(int i=0;i<s.size();i++)anshs2[i+1] = 1ll*anshs2[i] * p2%mod + s[i], anshs2[i+1]%=mod;
	
	for(int i=2;i<=n;i++){
		cin >> s;
		hs[0] = 0;
		int m = s.size();
		for(int j=0;j<m;j++)hs[j+1] = (1ll*hs[j]*p + s[j])%mod;
		for(int j=0;j<m;j++)hs2[j+1] = (1ll*hs2[j]*p2 + s[j])%mod;
		int res=0;
		for(int j=min(m,cnt);j>=1;j--){
			if(gethash2(1,j) == ((anshs2[cnt]-1ll*anshs2[cnt-j]*bs2[j]%mod)%mod+mod)%mod 
				&& gethash(1,j) == ((anshs[cnt] - 1ll*anshs[cnt-j] * bs[j]%mod)%mod+mod)%mod){
				res = j;
				break;
			}
		}
		for(int j=res;j<m;j++){
			ans += s[j];
			++ cnt;
			anshs[cnt] = 1ll*anshs[cnt-1] * p%mod + s[j];anshs[cnt]%=mod;
			anshs2[cnt] = 1ll*anshs2[cnt-1] * p2%mod + s[j];anshs2[cnt]%=mod;
		}
	}
	cout << ans;
	
	return 0;
}
 
