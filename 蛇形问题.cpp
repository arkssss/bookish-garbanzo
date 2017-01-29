/*
蛇形输出数组 
*/
#include <stdio.h>
#include <string.h> 
#define maxn 20

int a[maxn][maxn];


int main(){
		
	int n,x,y,tot;
	//输入 n*n的二维数组 
	scanf("%d",&n);

	//数组a清理
	memset(a,0,sizeof(a));
	 
	tot=a[x=0][y=n-1]=1;

	while(tot<n*n){
	
		while( x<n-1 && !a[x+1][y]) a[++x][y]=++tot;
		while( y>0 && !a[x][y-1] )  a[x][--y]=++tot;
		while( x>0 && !a[x-1][y])	a[--x][y]=++tot;
		while( y<n-1 && !a[x][y+1])	a[x][++y]=++tot;

	}

	for(int i=0;i<n;i++){

			for(int j=0; j<n ;j++){
	
				printf("%3d",a[i][j]);	

			}	
			
				printf("\n");

	}


}
 
