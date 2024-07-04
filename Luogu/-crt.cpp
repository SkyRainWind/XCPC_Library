int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1,y=0;return a;}
	int ret = exgcd(b,a%b,x,y);
	int t=x;x=y;y=t-a/b*y;
	return ret;
}

vector<pii>cr; // cr(ai,bi)  X = ai(mod bi)
ll crt(){
	ll s = 1;
	int m = cr.size();
	for(int i=0;i<m;i++)s *= cr[i].second;
	ll ans = 0;
	for(int i=0,x;i<m;i++){
		ll t = s / cr[i].second;
		int tinv;
		exgcd(t,cr[i].second,tinv,x);
		(ans += 1ll*cr[i].first*t%s*tinv%s)%=s; 
	}
	return (ans%s+s)%s;
}
