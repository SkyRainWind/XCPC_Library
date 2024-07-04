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

const int inf = 1e9,maxn=666;

char s[maxn];
int n,cnt=0;
int cl[maxn];

void ck(){
	int st[233],tp=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='(')st[++ tp]=i;
		else{
			if(tp<=0)return ;
			if((cl[st[tp]] == 0&&cl[i]!=0) || (cl[st[tp]]!=0&&cl[i]==0));
			else return ;
			-- tp;
		}
		if(i>=2 && cl[i]==cl[i-1] && cl[i]!=0)return ;
	}
	for(int i=1;i<=n;i++)printf("%d ",cl[i]);puts("");
	++ cnt;
}

void dfs(int x){
	if(x == n+1){
		ck();
		return ;
	}
	cl[x] = 0;dfs(x+1);
	cl[x] = 1;dfs(x+1);
	cl[x] = 2;dfs(x+1);
}

signed main(){
	scanf("%s",s+1); 
	n=strlen(s+1);
	dfs(1);
	printf("%d\n",cnt);

	return 0;
}


