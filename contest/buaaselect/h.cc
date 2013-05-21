#include<iostream>
using namespace std;
#define li			long long int

li n, x, y, c;

li swc(li s){
	li res=1+s*(s+1)*2;
	li koeta;
	if(y+s>n){
		koeta=y+s-n;
		res-=koeta*koeta;
	}
	if(y-s-1<0){
		koeta=s+1-y;
		res-=koeta*koeta;
	}
	if(x+s>n){
		koeta=x+s-n;
		res-=koeta*koeta;
	}
	if(x-s-1<0){
		koeta=s+1-x;
		res-=koeta*koeta;
	}
	if(x+y-s-1<0){
		koeta=1+s-x-y;
		res+=koeta*(koeta+1)/2;
	}
	if(x+y+s>2*n+1){
		koeta=x+y+s-2*n-1;
		res+=koeta*(koeta+1)/2;
	}
	if(x-y+s>n){
		koeta=x-y+s-n;
		res+=koeta*(koeta+1)/2;
	}
	if(y-x+s>n){
		koeta=y-x+s-n;
		res+=koeta*(koeta+1)/2;
	}
	return res;
}

li gao() {
    bool ans=true;
	li s=n,l=0,h=n*2;
	while(ans){
		if(h==0){
			return 0;
		}
		if(swc(s)>=c){
			if(swc(s-1)<c){
				return s;
			}
			h=s;
			s=(l+h)/2;
		}
		else{
			if(swc(s+1)>=c){
				return s+1;
			}
			l=s;
			s=(l+h)/2;
		}
	}
}

int main(){
    int T;
    cin >> T;
    while (T--) {
        cin>>n>>x>>y>>c;
        cout << gao() << endl;
    }
	return 0;
}
