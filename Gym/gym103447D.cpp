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

int s[222];
int mp1[22],mp2[22],mp3[22];

int dig(ll n){
	int cnt = 0;
	while(n){s[++ cnt] = n%10;mp3[n%10]++, n/=10;}
	return cnt;
}

int find(string s1,string s2){
	int n=s1.size(),m=s2.size(),idx=0;
	for(int i=0;i<n;i++){
		while(idx<m && s2[idx] != s1[i])++idx;
		if(idx==m)return 0;
		++idx;
	}
	return 1;
}

void solve(){
	ll n,m;
	cin >> n >> m;
	ll gd = __gcd(n,m);
	ll a=n/gd, b=m/gd;
	int len = dig(m);
	
	ll nw = n;
	for(int i=0;i<=9;i++)mp3[i]=0;
	while(nw){mp3[nw%10]++,nw/=10;}
	ll ansn = 9223372036854775807ll, ansm;
	for(int S=1;S<=(1<<len)-1;S++){
		int t[22];
		int ncnt = 0;
		for(int i=0;i<=9;i++)mp1[i] = mp2[i] = 0;
		for(int i=1;i<=len;i++)
			if((S&(1<<(i-1))))t[++ncnt] = s[i];
			else mp2[s[i]] ++;
		ll mm = 0;
		for(int i=ncnt;i>=1;i--)mm = mm*10 + t[i];
		if(mm%b != 0)continue;
		ll nn = a * (mm/b), tnn = nn;
		while(nn){mp1[nn%10]++, nn/=10;}
		int f = 0;
		for(int i=0;i<=9;i++){
			if(mp3[i] != mp1[i] + mp2[i])f = 1;
		}
		
		nn=tnn;
		string s1="";
		while(nn){s1+=nn%10+'0';nn/=10;}
		reverse(s1.begin(), s1.end());
		
		string s2="";
		nn=n;
		while(nn){s2+=nn%10+'0';nn/=10;}
		reverse(s2.begin(), s2.end());
		
//		cout <<"GG "<</s1<<" "<<s2<<'\n'; 
		if(!f && tnn < ansn && tnn && find(s1,s2))
			ansn = tnn, ansm = mm;
	}
	printf("%lld %lld\n",ansn,ansm);
}

signed main(){
	ios::sync_with_stdio(false); 
	int te;cin >> te;
	while(te --)solve();

	return 0;
}

