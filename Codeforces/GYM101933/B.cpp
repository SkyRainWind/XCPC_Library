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

signed main(){
	int n;scanf("%d",&n);
	int lst=0;
	for(int i=1;i<=n;i++){
		char s[15];scanf("%s",s+1);
		if(s[1] == 'm')++ lst;
		else{
			int m=strlen(s+1),res=0;
			for(int j=1;j<=m;j++)res = res*10+s[j]-'0';
			if(res != lst+1){
				puts("something is fishy");
				return 0;
			}
			++ lst;
		}
	}
	puts("makes sense");

	return 0;
}


