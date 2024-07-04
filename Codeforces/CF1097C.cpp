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

const int inf = 1e9;

char s[500005];
int bk[500005],bk2[500005];
int n;

signed main(){
	int imma=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		int m=strlen(s+1);
		int ct = 0,mn = inf;
		for(int j=1;j<=m;j++){
			if(s[j] == '(')++ ct;
			else -- ct;
			mn=min(mn,ct);
		}
		if(mn != ct);	// 一定不合法 
		else if(mn<0) bk[-mn]++; 
		
		int gg=0;ct=0;
		for(int j=1;j<=m;j++){
			if(s[j] == '(')++ ct;
			else{
				-- ct;
				if(ct < 0){gg=1;break;}
			}
		}
		if(gg);
		else if(ct)bk2[ct]++;
		else ++imma;
	}
	
	int ans=0;
	for(int i=0;i<=500000;i++)ans+=min(bk[i],bk2[i]);
	printf("%d\n",ans+imma/2);

	return 0;
}


