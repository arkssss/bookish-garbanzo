#include <stdio.h>
#include <string.h>
int main (){
	
	int m,n,row=0,len,record=0,min=0,newrow_record=0,count=0;
	scanf("%d%d",&m,&n);
	char DNA[m+5][n+5],temp;
	int same[100];
	memset(same,0,sizeof(same));
		
	while(row<m){
				
			//��ȡһ��һ�е����� 
			while(scanf("%s",DNA[row])==1){

				len=strlen(DNA[row]);
				//�ж������Ƿ����Ҫ�� 
				if(len!=n){
					printf("���벻����Ҫ��\n");
					continue;
					}
					else{
					break;
				}
			}		


		//����ǵ�һ�����룬����������Ϊ��Ҫ�Ƚ� 
			if(!row){
				row++;
				continue;
			
			}else if(row==1){
	
				for(int i=0;i<n;i++){
					if(DNA[0][i]==DNA[1][i]){
						record++;
					} 
				}	
				min=0;
				same[count++]=min;		
				row++;
				//��ʱ����ǰ�����HAMMING record ;ʣ�µ�ֻ��Ҫ��record+new_row && nwe_row ��Ҫ��֮������ROW hanmming  
			}else{
				

				//�ȵõ�min ��new_row ��hamming
				for(int i=0;i<n;i++){
					if(DNA[min][i]==DNA[row][i])
						{
							record++;
						}
				} 
			
				//��õ� new_row ��֮ǰ����row ��hanmming
				for(int i=row-1;i>=0;i--){
					for(int j=0;j<n;j++){
						if(DNA[row][j]==DNA[i][j]){
							newrow_record++;	
						}
					}							
				} 

				//���Ƚ� ȡrecordС�� 
					  if(record>newrow_record){
							record=newrow_record;
							min=row;
							memset(same,0,sizeof(same));	
							count=0;
							same[count++]=min;
					  }else if(record==newrow_record){
							//�������ȵ���� �����same�������� 
							same[count++]=row;
					  }

					newrow_record=0;
					row++;
			}						
			
	}	

				 for(int i=0;i<count;i++){
					row=same[i];
					printf("%s\n",DNA[row]);
				 }




} 
