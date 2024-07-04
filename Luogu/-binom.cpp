int fac[maxn], inv[maxn];

int pw(int x,int y){
	if(!y)return 1;
	if(y == 1)return x;
	int mid=pw(x,y>>1);
	if(y&1)return 1ll*mid*mid%mod*x%mod;
	return 1ll*mid*mid%mod;
}

int C(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}

//int lucas(int x,int y,int p){
//	return y==0 ? 1 : 1ll * lucas(x/p, y/p, p) * C(x%p, y%p, p) % p;
//}

signed main(){
	fac[0] = inv[0] = 1;
	for(int i=1;i<=maxn-5;i++)fac[i] = 1ll*fac[i-1]*i%mod;
	inv[maxn-5] = pw(fac[maxn-5], mod-2);
	for(int i=maxn-6;i>=1;i--)inv[i] = 1ll*inv[i+1]*(i+1)%mod;
