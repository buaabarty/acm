#include <iostream>
#include <cstdio>
#include <cstring>
#define N 256
#define BEGIN int main(){
#define END. return 0; }
#define begin {
#define end }
#define do
#define Procedure void
#define then
#define := =
#define and &&
#define not !
#define end; }
using namespace std;
int T, n;
Procedure Write(int n)
{
    printf("%d", n);
}
Procedure Write(char c)
{
    putchar(c);
}
Procedure Write(char *s)
{
    printf("%s", s);
}
Procedure Read(int &n)
begin
    char c := getchar();
    while (!((c >= '0') && (c <= '9'))) do
        c := getchar();
    n := 0;
    while ((c >= '0') && (c <= '9')) do
    begin
        n := n * 10 + c - '0';
        c := getchar();
    end;
end;
BEGIN
    Read(T);
    for (int ca := 1; ca <= T; ++ca)
    begin
        Read(n);
        Write("Case #");
        Write(ca);
        Write(":\n");
        for (int i := 1; i <= n; ++i)
            for (int j := 1; j <= n; ++j)
                if (j < n) then
                begin
                    Write((i - 1) * (n - 1) + j);
                    Write(' ');
                end
                else begin
                    Write(n * (n - 1) + i);
                    Write("\n");
                end;
    end;
END.
