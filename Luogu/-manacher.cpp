// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9;

//string s,ms="$#";
char s[22000005],ms[22000005];
int ans,n,p[22000005];

void manacher(){
	int mx=0,id=0;
	for(int i=1;i<n;i++){
		p[i] = mx>i?min(mx-i,p[id*2-i]):1;
		while(ms[i+p[i]]==ms[i-p[i]])++p[i];
		if(mx<i+p[i]){mx=i+p[i];id=i;}
		ans=max(ans,p[i]-1);
	}
}
	
signed main(){
	scanf("%s",s+1);
	int pq=strlen(s+1);
	ms[++n]='$',ms[++n]='#';
	for(int i=1;i<=pq;i++){
		ms[++n]=s[i];ms[++n]='#';
	}
	manacher();
	printf("%d\n",ans);

	return 0;
}

