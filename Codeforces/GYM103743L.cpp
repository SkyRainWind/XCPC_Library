#include<bits/stdc++.h>
#define up(l, r, i) for(int i = l, END##i = r;i <= END##i;++ i)
#define dn(r, l, i) for(int i = r, END##i = l;i >= END##i;-- i)
using namespace std;
typedef long long i64;
const int INF = 2147483647;
int qread(){
    int w = 1, c, ret;
    while((c = getchar()) >  '9' || c <  '0') w = (c == '-' ? -1 : 1); ret = c - '0';
    while((c = getchar()) >= '0' && c <= '9') ret = ret * 10 + c - '0';
    return ret * w;
}
#define mpr make_pair
#define pb push_back
#define pii pair<int,int>
vector<pii>vc;
char s[200005];
int main(){
    scanf("%s",s+1);
    int n=strlen(s+1);
    int ans=0;
    for(int i=1;i<=n;){
        int j=i;
        if(s[i] == 'B'){
            while(j+1 <= n && 2*i-(j+1) >= 1 && s[j+1] == 'C' && s[2*i-(j+1)] == 'A')++ j;
            int len = j-(i+1)+1;
            if(len)
	            vc.pb(mpr(len,(i-1)%2));
        }
        i=j+1;
    }
//    for(auto &it : vc){
////    	printf("(%d,%d\n)",it.first,it.second);
//        if(it.second==1)++ans, --it.first;
//    }
    int have = 0;
    for(auto it : vc){
    	int fg = 0;
    	if(it.second == 1){
    		++ ans;
    		-- it.first;
    		fg = 1;
    	}
        int qw = min(have + 1, it.first);
//        printf("~~ %d\n",qw);
        ans += qw;
      	if(have == 0 && (it.first == 0 && fg));
		else have ++;
    }
    cout << ans << '\n';

    return 0;
}
// ABCAAABCCC

