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

char s[maxn],t[maxn];
int n,m,nxt[maxn];

void getnxt(){
	nxt[1] = 0;
	int j = 0;
	for(int i=2;i<=m;i++){
		while(j && t[j+1] != t[i])j = nxt[j];
		if(t[j+1] == t[i])++ j;
		nxt[i] = j;
	}
}

void kmp(){
	int j = 0;
	for(int i=1;i<=n;i++){
		while(j && t[j+1] != s[i])j = nxt[j];
		if(t[j+1] == s[i])++ j;
		if(j == m){
			printf("%d\n",i-m+1);
		}
	}
}

signed main(){
	scanf("%s",s+1);scanf("%s",t+1);
	n=strlen(s+1), m=strlen(t+1);
	getnxt();
	kmp();
	for(int i=1;i<=m;i++)printf("%d ",nxt[i]);puts("");

	return 0;
}


