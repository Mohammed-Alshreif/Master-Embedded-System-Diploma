
#include <stdio.h>
#include <stdlib.h>

void main (){

	printf("Enter the matrex size ");
	fflush(stdout);
	int a,b;fflush(stdout);
	scanf("%d %d",&a,&b);
	int x[a][b],y[b][a];


	for(int i=0;i<=a-1;i++){
		for(int j=0;j<=b-1;j++){
			printf("Enter the matrex emint[%d][%d] \r\n",i,j);
			fflush(stdout);
			scanf("%d",&x[i][j]);
		}
	}
	for(int i=0;i<=a-1;i++){
			for(int j=0;j<=b-1;j++){
				y[j][i]=x[i][j];
			}
		}
	for(int i=0;i<=a-1;i++){
				for(int j=0;j<=b-1;j++){
					printf("the matrex emint %d \t",x[i][j]);

				}
				printf("\r\n");
			}
	for(int i=0;i<=b-1;i++){
			for(int j=0;j<=a-1;j++){
				printf("the matrex emint %d \t",y[i][j]);

			}
			printf("\r\n");
		}


}
