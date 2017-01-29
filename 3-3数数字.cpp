#include <stdio.h>
#include <string.h>
int main (){
	int res[15];
	memset(res,0,sizeof(res));
	char temp;

	while(scanf("%c",&temp)==1 && temp!='\n'){

			res[temp-'0']++;		
						
	}	
    
	for(int i=0;i<=9;i++){
		printf("%d ",res[i]);
	}


}

