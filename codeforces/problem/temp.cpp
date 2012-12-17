#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL = 30000 ;
class CBigInt{
public:
    char data[MAXL] ;
    int l ;
    CBigInt() ;
    CBigInt(int i) ;
    CBigInt(CBigInt &bi);
    CBigInt& add(CBigInt &bi) ;
    CBigInt& mul(CBigInt &bi) ;
    CBigInt& operator+(CBigInt &bi) ;
    CBigInt& operator*(CBigInt &bi) ;
    CBigInt& operator+=(CBigInt &bi) ;
    CBigInt& operator*=(CBigInt &bi) ;
    CBigInt& operator=(CBigInt &bi) ;
    void init(int i);
    void clear() ;
    void output() ;
}a, b;

void CBigInt::init(int i){
    l = 0 ;
    memset(data,0,sizeof(data)) ;
    do{
        data[l] = i % 10 ;
        i /= 10 ;
        l ++ ;
    }while(i);
}

void CBigInt::clear(){
    l = 1 ;
    memset(data,0,sizeof(data)) ;
}

CBigInt::CBigInt(){
    clear();
}

CBigInt::CBigInt(int i){
    init(i);
}

CBigInt::CBigInt(CBigInt &bi){
    memset(data,0,sizeof(data));
    int i ;
    l = bi.l ;
    for ( i = 0 ; i < l ; i ++ ) data[i] = bi.data[i] ;
}

CBigInt& CBigInt::add(CBigInt &bi){
    int i = 0 ;
    int p = 0 ;
    while ( i < l || i < bi.l ){
        p += data[i] + bi.data[i] ;
        data[i] = p % 10 ;
        p /= 10 ;
        i ++ ;
    }
    if ( p ) {
        data[i] = p ;
        i ++ ;
    }
    l = i ;
    return *this ;
}

CBigInt& CBigInt::mul(CBigInt &bi){
    int tmp[MAXL] ;
    int i , j , p ;
    memset(tmp,0,sizeof(tmp)) ;
    for ( i = 0 ; i < l ; i ++ ){
        for ( j = 0 ; j < bi.l ;j ++ ){
            tmp[i + j] += data[i] * bi.data[j] ;
        }
    }
    j = l + bi.l + 1;
    p = 0 ;
    for ( i = 0 ; i < j ; i ++ ){
        p += tmp[i] ;
        data[i] = p % 10 ;
        p /= 10 ;
    }
    if ( p ){
        data[i] = p ;
        i ++ ;
    }
    while ( !data[i] ) i -- ;
    l = i + 1 ;
    return *this ;
}

CBigInt& CBigInt::operator+(CBigInt &bi){
    CBigInt *p = new CBigInt(*this) ;
    return p->add(bi) ;
}

CBigInt& CBigInt::operator*(CBigInt &bi){
    CBigInt *p = new CBigInt(*this) ;
    return p->mul(bi);
}

CBigInt& CBigInt::operator+=(CBigInt &bi){
    add(bi);
    return *this ;
}

CBigInt& CBigInt::operator*=(CBigInt &bi){
    mul(bi);
    return *this ;
}

CBigInt& CBigInt::operator=(CBigInt &bi){
    int i;
    memset(data,0,sizeof(data));
    l = bi.l ;
    for ( i = 0 ; i < l ; i ++ ) data[i] = bi.data[i] ;
    return *this ;
}

void CBigInt::output(){
    int i;
    for ( i = l - 1 ; i >= 0 ; i -- ) printf("%d",data[i]) ;
    //for ( i = l - 1 ; i >= 0 ; i -- )putchar('0' + data[i]);
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {

    }
    return 0;
}
