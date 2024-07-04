namespace rho{
	inline LL mul(LL a,LL b,LL p){
		a %= p; b %= p;
		if(p<=1e9)return 1ll*a*b%p;
		if(p<=1e12)return (((a*(b>>20)%p)<<20)%p+a*(b&(1<<20)-1))%p;
		LL d=1ll*floor(a*(long double)b/p);
		LL res=(a*b-d*p)%p;if(res<0)res += p;
		return res;
	}
	
	inline LL pw(LL a,LL b,LL mod){
		LL res=1;
		for(;b;b>>=1){
			if(b&1)res=mul(res,a,mod);
			a=mul(a,a,mod);
		}
		return res;
	}
	
	inline int check(LL a,LL x,LL times,LL n){
		LL tmp=pw(a,x,n);
		while(times --> 0){
			LL lst=mul(tmp,tmp,n);
			if(lst==1&&tmp!=1&&tmp!=n-1)return 1;
			tmp=lst;
		}
		return tmp!=1;
	}
	int base[]={2,3,5,7,11,13,17,19,23};
	const int S=8;
	int miller(LL n){
		for(int i=0;i<=S;i++){
			if(n==base[i])return 1;
			if(n%base[i]==0)return 0;
		}
		LL x=n-1,times=0;
		while(x%2==0)x/=2,++times;
		for(int i=0;i<=S;i++){
			if(check(base[i],x,times,n))return 0;
		}
		return 1;
	}
	
	#define F(x) ((mul(x,x,n)+c)%n)
	inline LL rho(LL n,LL c){
		LL x=rand()%n,y=F(x);
		while(x^y){
			LL w=__gcd(abs(x-y),n);
			if(w>1&&w<n)return w;
			x=F(x);y=F(y);y=F(y);
		}
		return 0;
	}
	
	LL ans=0;
	void calc(LL x){
		if(miller(x)){
			ans=max(ans,x);
			return ;
		}
		LL res=0;
		while((res=rho(x,rand()%x))==0);
		calc(res);calc(x/res);
	}
}

rho::miller(n) // is prime

rho::ans=0
rho::calc(x)	// ans is max prime divisor of x
