/*18
12 17
8 25
11 3
28 24
8 27
25 11
24 28
17 12
19 23
27 8
28 27
27 24
23 19
3 11
24 27
25 8
11 25
27 28
0
*/

#include <cstdio>
#include <map> 
#include <iostream>
using namespace std;

int main (){

//freopen("input.txt","r",stdin);	
//freopen("output.txt","w",stdout); 

map<pair<int,int>,int>dict;

int n,loc,tar;	

while(scanf("%d",&n)==1 && n){


for(int i=0;i<n;i++){
	
	scanf("%d%d",&loc,&tar);
	pair<int,int>tmp(loc,tar);
	pair<int,int>tmpForCom(tar,loc);

	//如过可以匹配到则这个可以不存 
	if(dict.count(tmpForCom)){
	
		dict[tmpForCom]--;
		//减到0则没有了 
		if(dict[tmpForCom]==0){
	
			dict.erase(tmpForCom);
	
		}		

	}else{
	
			if(!dict.count(tmp)){
				dict[tmp]=1;
			}else{
				dict[tmp]++;
			} 

	}


	

}
	if(dict.empty()){
		
		cout<<"YES"<<endl;
	
	}else{
	
		cout<<"NO"<<endl;
	}
	
	dict.clear();

}


	return 0;
} 

