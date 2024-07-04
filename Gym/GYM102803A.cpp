// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;

const int inf = 1e9, INF = 0x3f3f3f3f;

int a,b;
ll n;

ull s0(ll l, ll r){
	return r-l+1;
}

ull s1(ll l, ll r){
	ull s1 = l+r, s2 = r-l+1;
	if(s1%2 == 0)s1 /= 2;else s2 /= 2;
	return s1*s2;
}

ull sv2(ll x){
	ull t1 = x, t2 = x+1, t3 = 2*x+1;
	if(x%2 == 0)t1 /= 2;
	else t2 /= 2;
	if(t1%3 == 0)t1 /= 3;
	else if(t2%3 == 0)t2 /= 3;
	else t3 /= 3;
	return t1*t2*t3;
}

ull s2(ll l, ll r){
	return sv2(r) - sv2(l-1);
}

ull sv3(ll x){
	ull t1 = x, t2 = x+1;
	if(t1%2 == 0)t1 /= 2;else t2 /= 2;
	return t1*t2*t1*t2;
}

ull s3(ll l, ll r){
	return sv3(r) - sv3(l-1);
}

ull ss(ll l, ll r,int id){
	if(id == 0)return s0(l,r);
	if(id == 1)return s1(l,r);
	if(id == 2)return s2(l,r);
	if(id == 3)return s3(l,r);
}

ull solve(long long n,int id){
	ull ans = 0;
	for(ll l=1,r;l<=n;l=r+1){
		r = n/(n/l);
		ans += 1ull * (n/l) * ss(l, r, id);
	}
	return ans;
}

signed main(){
	cin >> a >> b >> n;
	cout << (solve(n,a)^solve(n,b)) << '\n';

	return 0;
}

