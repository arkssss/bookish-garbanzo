#include <stdio.h>
#include <string.h>
#define MAXN 1000
int main (){
	char s[MAXN];
	scanf("%s",s);
	int len=strlen(s);
	char ini;
	int flag,res;
	for(int i=0;i<len;i++){
			if(!i){
				ini=s[i];
			}	
		if(s[i]==ini){
			for (int j=1;j<i;j++){
					if(s[j]==s[i+j]){
						flag=1;
						continue;
					}else{
						flag=0;
						break;
					}
			}
		}	
		if(flag){
			res=i;
			break;
		}

	}


		printf("%d",res);

	
}
