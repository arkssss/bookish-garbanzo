#include <stdio.h>
#define MAXN 1010
int main (){
	
		int n,a[MAXN],b[MAXN];
		int kase=0; 
		while(scanf("%d",&n)==1 && n!=0){
				
			printf("Game %d\n",++kase);
					//获取样例序列 
				for(int i=0;i<n;i++){
					scanf("%d",&a[i]);
				}				
					//无限循环获取测试序列 
				for(;;){
					int A=0,B=0;
					//每一组测试序列 
					for(int i=0;i<n;i++){
						
						scanf("%d",&b[i]);
						if(b[i]==a[i])
							A++;			
							
					}	
					//如果为全0数列，则跳出无限循环			
					if(!b[0])
					  break;

						for(int d=0;d<=9;d++){
								int c1=0,c2=0;
							for(int i=0;i<n;i++){
								if(a[i]==d) c1++;
								if(b[i]==d) c2++;
							}
							if(c1>c2){
								B+=c2;
							}else{
								B+=c1;
							}

						}

					printf("   (%d,%d)\n",A,B-A);
				}


		
		}

		return 0;

} 
