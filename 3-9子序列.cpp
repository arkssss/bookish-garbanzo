#include <stdio.h>
#include <string.h>
#define MAXN 1000
int main (){
	
	char s[MAXN],t[MAXN];
	scanf("%s%s",s,t);	
	int lens=strlen(s);
	int lent=strlen(t);
	int flag=1,count=0,k,j;
	
	for(int i=0;i<lent;i++){
		
		if(t[i]==s[0]){
				
			for(j=1;j<lens;j++){
					if(j==1){
						count=i;
					}
			   for(k=count+1;k<lent;k++){
	
					if(s[j]==t[k]){
						count=k;
						break;
					}


			   }
					//���˵��t�����ѯ�궼û��ƥ���� 
				   if(k==lent){
						printf("false"); 	
						return 0;
					} 

			
			} 

				 printf("true");
			     	return 0;


		}			


} 
         printf("flase");
		return 0;

}
