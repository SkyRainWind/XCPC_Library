// by SkyRainWind
#include <cstdio>
#include <vector>
#include <cassert>
#include <string>
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

string s,t;
char res[300005];

signed main(){
	cin>>s>>t;
	int n=s.size();
	sort(s.begin(),s.end());sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	int lp=0, lp0=(n+1)/2-1, rp = 0, rp0 = n/2 - 1;
	int lsp=0, rsp = s.size()-1;
	
	for(int i=0;i<s.size();i++){
		if(i&1^1){
			if(s[lp] < t[rp]){
				res[lsp] = s[lp];
				++ lsp;
				++ lp;
			}else{
				res[rsp] = s[lp0];
				-- rsp;
				-- lp0;
			}
		}else{
			if(s[lp] < t[rp]){
				res[lsp] = t[rp];
				++ lsp;
				++ rp;
			}else{
				res[rsp] = t[rp0];
				-- rsp;
				-- rp0;
			}
		}
	}
	printf("%s", res);

	return 0;
}

