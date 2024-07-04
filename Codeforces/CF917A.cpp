// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define pii pair<int,int>

using namespace std;

typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;
char s[5005];
signed main(){
	scanf("%s",s +1);
	int n=strlen(s+1), ans = 0;
	for(int i=1;i<=n;i++){
		int tot=0, num=0;
		for(int j=i;j<=n;j++){
			if(s[j] == '(')++ tot;
			if(s[j] == ')')-- tot;
			if(s[j] == '?')++ num, -- tot;
			
			if(tot == 0)++ ans;
			else if(tot < 0 && num > 0){
				tot += 2;
				num --;
			}else if(tot < 0 && num == 0)break;
		}
	}
	printf("%d\n",ans);

	return 0;
}

