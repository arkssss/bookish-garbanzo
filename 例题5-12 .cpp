/* 14
160 0 30 60 30
125 0 32 28 60
95 0 27 28 40
70 35 19 55 90
0 0 60 35 80
0 40 29 20 60
35 40 25 45 80
0 67 25 20 50
0 92 90 20 80
95 38 55 12 50
95 60 60 13 30
95 80 45 25 50
165 65 15 15 25
165 85 10 15 35
0
*/
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int manx=105;
int n;
double x[manx*2];


struct bulding{
	
	//x y �����½�Ϊ����ԭ�� 
	int id;
	double x,y,w,d,h;

	//���رȽϷ��� < ����sort���� �����½�Ϊ��׼ 
	bool operator < (const bulding & co) const{
	
		return x<co.x || (x==co.x && y<co.y);

	}


}b[manx]; 

//�ж�mx�����Ƿ���i�� 
bool cover(int i,const double  mx){
	
 return b[i].x<=mx && (b[i].x+b[i].w)>=mx;

}


//�ж�i��mx�����Ƿ�ɼ� 
bool visiable(int i,const double mx){
	
	//������ mx��������i��  
	if(!cover(i,mx)) return false;

	//������ mx������i�� ���ڵ�Ŀ�����ҵ���mx����building iǰ��Ľ���j ���ж����ǵĸ߶ȹ�ϵ ����ǰ���н����Ҹ߶�ֻҪ����i ���˳�  
	for(int j=0;j<n;j++){
	
		if(b[j].y<b[i].y && b[j].h>=b[i].h && cover(j,mx)) return false;

	}
		return true;
	

}







int main() {

		freopen("input.txt","r",stdin);

		int kase=0;
		//n�����ж��ٸ����� nΪ0ʱ����ѭ�� 
		while(scanf("%d",&n)==1 && n){
	
			for(int i=0;i<n;i++){
	
				scanf("%d%d%d%d%d",&b[i].x,&b[i].y,&b[i].w,&b[i].d,&b[i].h);
				//��ɢ������ 
				x[i*2]=b[i].x;
				x[i*2+1]=b[i].x+b[i].w;
				b[i].id=i+1;
				
			}	
				

		
			//������n 
			sort(b,b+n);			
			sort(x,x+2*n);
			//ȥ���ظ�����ɢx���� ��mΪ������ܸ��� 
			int m=unique(x,x+2*n)-x;
					
			printf("For map %d,the visible building are number as follows:\n%d",++kase,b[0].id);
					
			
			for(int i=1;i<n;i++){
		
				int vis=0;
		
				for(int j=0;j<m-1;j++){
	
					//ȡx[j] ��x[j+1]�����һ��ֵ �������2��� 
					if(visiable(i,(x[j]+x[j+1])/2)){
						
						vis=1;
						break;
						
					}	


				}	
					if(vis){
						printf(" %d",b[i].id);
					}

			}			





		} 


			return 0;
}













