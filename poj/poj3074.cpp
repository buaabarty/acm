#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 800
#define M 350

const int head=0;
const int V=N*M;

int U[V],D[V],L[V],R[V],C[V];

int S[N],O[N],Row[V];

int size;
int H[N];

char mapv[N];
int mapx[N];
int mapy[N];
int ak,hs;

char s[10][9];

void Remove(int c)
{
	int i,j;
	L[R[c]]=L[c];
	R[L[c]]=R[c];
	for(i=D[c];i!=c;i=D[i]){
		for(j=R[i];j!=i;j=R[j]){
			U[D[j]]=U[j];
			D[U[j]]=D[j];
			S[C[j]]--;
		}
	}
}

void Resume(int c)
{
	int i,j;
	for(i=U[c];i!=c;i=U[i]){
		for(j=L[i];j!=i;j=L[j]){
			U[D[j]]=D[U[j]]=j;
			S[C[j]]++;
		}
	}R[L[c]]=L[R[c]]=c;
}

int Search(int k)
{
	int min,i,j,c;
	if(R[head]==head){
		ak=k;return 1;
	}
	for(min=V,c=0,i=R[head];i!=head;i=R[i]){
		if(S[i]<min) min=S[i],c=i;
	}

	Remove(c);

	for(i=D[c];i!=c;i=D[i]){

		for(j=R[i];j!=i;j=R[j])
			Remove(C[j]);
		O[k]=Row[i];
		if(Search(k+1)) return 1;

		for(j=L[i];j!=i;j=L[j])
			Resume(C[j]);
	}
	Resume(c);

	return 0;
}

void AddNode(int f,int &h,int x)
{
	S[x]++;
	C[size]=x;
	Row[size]=f;

	U[size]=U[x];
	D[U[x]]=size;
	D[size]=x;
	U[x]=size;

	if(h==-1){
		L[size]=R[size]=size;
		h=size;
	}
	else{
		L[size]=L[h];
		R[L[h]]=size;
		R[size]=h;
		L[h]=size;
	}
	size++;
}

int main()
{
	int i,j,k;

	while(gets((char *)s),s[0][0]!='e'){

		memset(S,0,sizeof(S));

		for(i=0;i<=324;i++){
			R[i]=i+1;L[i+1]=i;
			U[i]=D[i]=i;
		}R[324]=0;

		size=325;hs=0;
		memset(H,-1,sizeof(H));

		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				if(s[i][j]!='.'){
					AddNode(hs,H[hs],i*9+j+1);
					AddNode(hs,H[hs],i*9+81+s[i][j]-'0');
					AddNode(hs,H[hs],j*9+162+s[i][j]-'0');
					AddNode(hs,H[hs],(i/3*3+j/3)*9+243+s[i][j]-'0');
					mapv[hs]=s[i][j];
					mapx[hs]=i;mapy[hs]=j;
					hs++;
				}
				else{
					for(k=1;k<=9;k++){
						AddNode(hs,H[hs],i*9+j+1);
						AddNode(hs,H[hs],i*9+81+k);
						AddNode(hs,H[hs],j*9+162+k);
						AddNode(hs,H[hs],(i/3*3+j/3)*9+243+k);
						mapv[hs]=k+'0';
						mapx[hs]=i;mapy[hs]=j;
						hs++;
					}
				}
			}
		}
		Search(0);
		for(i=0;i<ak;i++)
			s[mapx[O[i]]][mapy[O[i]]]=mapv[O[i]];

		puts((char *)s);
	}
	return 0;
}
