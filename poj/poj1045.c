#include <stdio.h>
#include <math.h>
int main()
{
    double vs, r, c, w;
    int n;
    scanf("%lf%lf%lf%d", &vs, &r, &c, &n);
    while (n--)
    {
        scanf("%lf", &w);
        printf("%.03lf\n", c*r*w*vs/sqrt(1.0+c*r*w*c*r*w));
    }
    return 0;
}
