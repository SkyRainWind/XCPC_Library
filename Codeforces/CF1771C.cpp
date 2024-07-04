// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long ll;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e5+5;

int n,a[maxn];
int notpm[maxn],pm[maxn],pcnt=0;

void xxs(){
	notpm[1] = 1;
	for(int i=2;i<=maxn-5;i++){
		if(!notpm[i])pm[++pcnt]=i;
		for(int j=1;j<=pcnt&&1ll*pm[j]*i<=maxn-5;j++){
			notpm[i*pm[j]] = 1;
			if(i%pm[j] == 0)break;
		}
	}
}

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	set<int>S;
	int fg = 0;
	for(int i=1;i<=n;i++){
		int tmp = a[i];
		if(tmp == 1)continue;
		for(int j=1;j<=pcnt;j++){
			if(1ll*pm[j]*pm[j] > a[i] || pm[j] > tmp)break;
			if(tmp%pm[j] == 0){
				if(S.count(pm[j])){
					fg = 1;
					break;
				}
				while(tmp%pm[j] == 0)tmp /= pm[j];
				S.insert(pm[j]);
			}
		}
		if(tmp != 1){
			if(S.count(tmp))fg = 1;
			else S.insert(tmp);
		}
		if(fg)break;
	}
	puts(fg ? "YES" : "NO");
}

signed main(){
	xxs();
	int te;scanf("%d",&te);
	while(te --)solve();

	return 0;
}

