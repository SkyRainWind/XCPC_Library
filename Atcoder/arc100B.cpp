// by Balloons
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

int n,a[maxn], sum[maxn]; 

int getsum(int l,int r){return sum[r] - sum[l-1];}

int check(int x,int lim){
	int s1 = getsum(1, x);
	int l = 1, r = x, lf1, lf2;
	while(l <= r){
		int mid = l+r>>1;
		if(getsum(mid, r) >= (s1 - lim)/2)lf1 = mid, l = mid+1;
		else r = mid-1;
	}
	l = 1, r = x;
	while(l <= r){
		int mid = l+r>>1;
		if(getsum(mid, r) <= (s1 + lim)/2)lf2 = mid, r = mid-1;
		else l = mid+1;
	}
	if(lf1 > lf2)return 0;
	
	debug();
	
	int s2 = getsum(x+1, n);
	l = x+1, r = n;
	int ri1, ri2;
	while(l <= r){
		int mid = l+r>>1;
		if(getsum(mid, n) >= (s2 - lim)/2)ri1 = mid, l = mid+1;
		else r = mid-1;
	}
	l = x+1, r = n;
	while(l <= r){
		int mid = l+r>>1;
		if(getsum(mid, n) <= (s2 + lim)/2)ri2 = mid, r = mid-1;
		else l = mid+1;
	}
	if(ri1 > ri2)return 0;
	return 1;
}

signed main(){
	cin >> n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)sum[i] = sum[i-1] + a[i];
	int r = 1e15;
	printf("%d\n",check(2,2));
	for(int i = 2;i<=n-2;i++){
		int l = 0, r = 1e15, ans;
		while(l <= r){
			int mid = l+r>>1;
			if(check(i, mid))r = mid-1, ans = mid;
			else l = mid+1;
		}
		r = min(r, ans);
	}
	cout << r << endl;

	return 0;
}


