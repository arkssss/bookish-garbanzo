#include <stdio.h>
#include <string.h>
#define M 5
#define N 5
void show(const char square[][5]){
		for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			printf("%c ",square[i][j]);
		}
			printf("\n");
	}
} 

int main (){
	
	char square[M][N]={{'T','R','G','S','J'},{'X','D','O','K','I'},{'M',' ','V','L','N'},{'W','P','A','B','E'},{'U','Q','H','C','F'}};
	const char* msg="This puzzle has final configuration";
	int space_row=2,space_clw=1;
	
	char temp;
	
	while(scanf("%c",&temp)==1 && temp!='0' &&temp!='\n'){
	
		switch(temp){
			case 'A':
				if(space_row){
					square[space_row][space_clw]=square[space_row-1][space_clw];
					square[space_row-1][space_clw]=' ';
					space_row--;
				} else{
					printf("%s",msg);
				}
					break;
			case 'B':
				if(M-1-space_row){
							square[space_row][space_clw]=square[space_row+1][space_clw];
							square[space_row+1][space_clw]=' ';
							space_row++;
						} else{
							printf("%s",msg);
					}
					break;
			case 'L':
				if(space_clw){
					square[space_row][space_clw]=square[space_row][space_clw-1];
					square[space_row][space_clw-1]=' ';
					space_clw--;
				} else{
					printf("%s",msg);
				}
					break;
			case 'R':
				if(N-1-space_clw){
					square[space_row][space_clw]=square[space_row][space_clw+1];
					square[space_row][space_clw+1]=' ';
					space_clw++;
				} else{
					printf("%s",msg);
				}
					break;
				
			default :
				if(temp-'0'){
					break;
				}else{
					printf("%s",msg);
					break;
				}
				

		}


	}





			show(square);







}
