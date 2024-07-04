// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Madoka"<<endl
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f,maxn=1e6+5;

char s[maxn];
int nxt[maxn],n;

void getnxt(){
	nxt[1] = 0;
	for(int i=2;i<=n;i++){
		int j = nxt[i-1];
		while(j && s[i] != s[j+1])j = nxt[j];
		if(s[i] == s[j+1])++ j;
		nxt[i] = j;
	}
}

int hs[1000005];

signed main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	getnxt();
	int res = -1, id;
	for(int i=nxt[n];i;i=nxt[i]){
		for(int j=2;j<=n-1;j++){
			if(i == nxt[j]){
				res = i;
				break;
			}
		}
		if(~res)break;
	}
	if(~res){for(int i=1;i<=res;i++)putchar(s[i]);}
	else puts("Just a legend");

	return 0;
}


