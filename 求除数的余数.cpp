#include <stdio.h>
#include <string.h>
#define MAXN 1000
int main (){
	int a,b,res,left=0,flag,count=0,arr[MAXN],v[MAXN],n;
	scanf("%d%d",&a,&b);
	memset(arr,0,sizeof(arr));
	memset(v,0,sizeof(v));
	printf("%d.(",a/b);
	
 
	while(v[left]!=2 && count<1000){
		  if(!left){
			res=a/b;
		    left=a%b;
			v[left]++;	
			continue;		
			  } 


		left*=10;
		//打印 
		res=left/b;
		left=left%b;
		v[left]++;
		arr[count++]=res;

	}		

	for(int i=0;i<count;i++){
			
			printf("%d",arr[i]);
			if(i==count-1){
				printf(")");	
			}	
	}
		printf(" 循环长度为%d",count);



	
}
