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

int f[233333]; 

signed main(){
	freopen("104077E.txt","w",stdout);
	f[0]=1;
	for(int i=1;i<=100000;i++)f[i]=(i%3==0)?(f[i/3]+1):(f[i-1]+1);
	for(int i=1;i<=10000;i++){
		printf("%d%c",f[i]," \n"[i%27==0]);
//		if(i%9==8)printf("%d%c",f[i]," \n"[(i+1)%81==0]);
	}

	return 0;
}

