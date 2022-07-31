#include <stdio.h>
#include <stdlib.h>
void main (){
	double l=0,r,m;
	    double n;
	    scanf("%lf", &n);
        r=n;
	    m=(l+r)/2;
	    while (abs(n-m*m) > 0.001) {
	        m = (l + r) / 2;
	        if (m * m < n) l = m ;
	        else r = m ;
	    }
	   printf("%.3lf", m);
}
