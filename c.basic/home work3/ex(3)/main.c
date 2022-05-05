
#include "stdio.h"
void main (){
	float q[2][2],w[2][2];
	printf("Enter the elment in matrex 1:\r\n");
	for(int i=0;i<2;i++){
		for(int y=0;y<2;y++){
			printf("Enter the elment [%d+1][%d+1]in matrex:",i,y);
			fflush(stdout);
			scanf("%f",&q[i][y]);
		}
	}
	printf("Enter the elment in matrex 2: \r\n");
	for(int i=0;i<2;i++){
		for(int y=0;y<2;y++){
			printf("Enter the elment [%d+1][%d+1]in matrex:",i,y);
			fflush(stdout);
			scanf("%f",&w[i][y]);
		}
	}
	for(int i=0;i<2;i++){
		for(int y=0;y<2;y++){
			printf(" the sum %f \t",(q[i][y]+w[i][y]));
		}
		printf("\r\n");
	}

}

