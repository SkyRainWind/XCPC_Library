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

int n;
char s[233];

signed main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int t1=0,t2=0;
	for(int i=1;i<=n;i++)if(s[i] == 'L')++t1;else ++t2;
	int t=0;
	for(int i=1;i<n;i++){
		if(s[i] == 'L')++t;
		int qw=i-t;
		if(t == t1-t || qw == t2-qw);
		else{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");

	return 0;
}

