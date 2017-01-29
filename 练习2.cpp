#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>
using namespace std;

const int maxn=20;



int main (){

//	freopen("input1.txt","r",stdin);

	int t,ti,TmpNum;
	vector <int> tmp; 
	map<vector<int>,int>dict;
	
	scanf("%d",&t);
	
	for(int i=0;i<t;i++){
	
		scanf("%d",&ti);
	
		for(int j=0;j<ti;j++){	
	
			scanf("%d",&TmpNum);
			tmp.push_back(TmpNum);		

		}


		for(int k=0;k<1000;k++){
		
			int head=tmp[0];
				
			for(int q=0;q<ti;q++){
			
				if(q==ti-1){
	
				tmp[q]=abs(tmp[q]-head);

				}else{
		
				tmp[q]=abs(tmp[q]-tmp[q+1]);	
			}
			} 
		
			if(!dict.count(tmp)){
	
				dict[tmp]=1;			
			
			}else {
	
				sort(tmp.begin(),tmp.end());
				if(tmp[ti-1]==0){
				
					cout<<"ZERO\n";	
					break;
	
				} else{
	
					cout<<"LOOP\n";
					break;
				} 
			


			}	
	

		}	

		tmp.clear();
		dict.clear();		
	
	}
			
		return 0;
	


}
