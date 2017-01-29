#include <cstdio>
#include <map>
#include <iostream>
#include <string>
#include <set> 

using namespace std;
const int Maxnrow = 10005;
const int Maxnclw = 15;


int main (){
	
	//用于字符串和整数的映射 
	map <string , int> dict;

	freopen("inputfor5-9.txt","r",stdin);

	int row,clw,indeti=0;
		
	char ar[100],coma;
	
	int db[Maxnrow][Maxnclw];

	//有row clw的输入 且都不为0 
	while(scanf("%d%d",&row,&clw)==2 && (row && clw)){
	
		
		memset(db,0,sizeof(db));

		for(int j=0;j<row;j++){
		

		for(int i=0;i<clw-1;i++){
	
			scanf("%[^,]%c",ar,&coma);	
			string s(ar);
			if(!dict.count(s)) dict[s]=indeti++;
			db[j][i]=dict[s]; 
	
		}
		
		    scanf("%s",ar); 
			string s(ar);
			if(!dict.count(s)) dict[s]=indeti++;
			db[j][clw-1]=dict[s]; 


	}
		
		
		//开始判断 vis映射 用于比较行行列列 
		map<pair <int ,int > ,int >vis;

		int ok=0;		

		//列1的循环 
		for(int c1=0;c1<clw;c1++){
		
			//列2的循环 
			for(int c2=c1+1;c2<clw;c2++){
		
				//行的循环			
				for(int r=0;r<row;r++){
	
				pair <int ,int >pos(db[r][c1],db[r][c2]);
							
				if(vis.count(pos)){
	
					cout<<"NO\n";
					cout<<vis[pos]+1<<' '<<r+1<<'\n'<<c1+1<<' '<<c2+1<<'\n';
			
					break;
				} 
		
		
				vis[pos]=r;								

	
				} 

			  if(ok)
	
				break;
			  
	
			}
			
			if(ok) break;

		} 
	
 
			if(!ok) cout<<"YES\n"; 
		

			return 0;


	}



}



//
//
//	
//	for(int i=0;i<row;i++){
//		for(int j=0 ;j<clw;j++){
//			cout<<db[i][j]<<' ';
//		}
//			cout<<'\n';
//	} 

















