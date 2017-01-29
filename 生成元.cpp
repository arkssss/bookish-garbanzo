#include <stdio.h>
#include <string.h>
#define MAXN 100005
int ans[MAXN];
int main (){
	

	memset(ans,0,sizeof(ans));
	
	for (int i=1;i<MAXN;i++){
		int m=i,n=i;
		while(n){
			m+=n%10;
			n/=10;
		}
		
		if(ans[m]==0 || ans[m]>i){
				
				ans[m]=i;

        }
		
	}
		
	int t,temp;
	scanf("%d",&t);
	while(t--){
				
		scanf("%d",&temp);
		printf("%d\n",ans[temp]);	
	}

  return 0;



}
