#include <stdio.h>
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
int main(){
    short x,a,b,n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        a=0,b=100;
        while(n--){scanf("%d",&x);a=max(a,x);b=min(b,x);}
        printf("%d\n",(a-b)<<1);
    }
    return 0;
}
