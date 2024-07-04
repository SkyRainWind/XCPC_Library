// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f, maxn=2e5+5;

char s[maxn];
int k,n,ans;
int nxt[maxn];

void getnxt(char *t,int nn){
	nxt[1] = 0;
	int j = 0;
	for(int i=2;i<=nn;i++){
		while(j && t[j+1] != t[i])j = nxt[j];
		if(t[j+1] == t[i])++ j;
//		while(2*j>=i)j = nxt[j];
		nxt[i] = j;
		int nj = j;
		while(2*nj >= i)nj = nxt[nj];
		if(nj>=k && i>2*nj)++ans;
	}
//	for(int i=1;i<=nn;i++)printf("%d ",nxt[i]);puts("");
}

signed main(){
	scanf("%s",s + 1);
	scanf("%d",&k);
	n=strlen(s+1);
	
	for(int i=1;i<=n;i++)
		getnxt(s+i-1,n-i+1);
	cout<<ans;

	return 0;
}

