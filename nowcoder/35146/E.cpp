// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=2e5+5;

int notpm[maxn],pm[maxn],pcnt=0;
void xxs(){
	notpm[1]=1;
	for(int i=2;i<=maxn-5;i++){
		if(!notpm[i]){
			pm[++pcnt]=i;
		}
		for(int j=1;j<=pcnt&&i*pm[j]<=maxn-5;j++){
			notpm[i*pm[j]]=1;
			if(i%pm[j]==0)break;
		}
	}
}
ll pw(int x,int y){
	if(!y)return 1;
	if(y==1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid*x;
	return 1ll*mid*mid;
}

signed main(){
	ll n;
	cin>>n;
	if(n<=2)puts("0");
	else printf("1\n2 3\n");

	return 0;
}

