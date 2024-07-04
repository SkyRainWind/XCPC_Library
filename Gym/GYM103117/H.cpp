// by SkyRainWind
#include <bits/stdc++.h>
#define mpr make_pair
#define debug() cerr<<"Yoshino\n"
#define pii pair<int,int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long long LL;

const int inf = 1e9, INF = 0x3f3f3f3f;

map<string,string>mp;
string s;

signed main(){
	mp["chimasu"]="tte";
	mp["rimasu"]="tte";
	mp["mimasu"]="nde";
	mp["bimasu"]="nde";
	mp["nimasu"]="nde";
	mp["kimasu"]="ite";
	mp["gimasu"]="ide";
	mp["shimasu"]="shite";
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		if(s=="ikimasu"){
			cout<<"itte"<<endl;
			continue;
		 } 
		int  len=s.size();
		string str1=s.substr(len-1-6,7);
		string str2=s.substr(len-1-5,6);
		int len1=mp[str1].size(),len2=mp[str2].size();
		if(len1!=0){
			for(int i=0;i<len-7;i++)cout<<s[i];
			cout<<mp[str1]<<endl;
		}
		if(len2!=0){
			for(int i=0;i<len-6;i++)cout<<s[i];
			cout<<mp[str2]<<endl;
		}
	}
	return 0;
}

