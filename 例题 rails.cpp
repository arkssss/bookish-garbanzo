#include <cstdio>
#include <stack>
#include <iostream>
const int maxn=1005;
using namespace std;
int main (){
//	freopen("i.txt","r",stdin);
//	freopen("o.txt","w",stdout);
	//输入的出站序列 
	int T,target[maxn];
	//进站序列		
	stack <int> dict;
	
	while(scanf("%d",&T)==1 && T!=0){
		int nextcom=0;
	for(;;){
	//接受输入 
	for(int i=1;i<=T;i++)
	{
		scanf("%d",&target[i]);
		if(!target[i]){
			nextcom=1;
			break;
		}
	}

	if(nextcom) {
		break;
	}		

	int A=1,B=1,ok=1;
	while(B<=T){
	
		if(A==target[B]) {
			A++;B++;
		}else if(!dict.empty() && dict.top()==target[B]) {
			dict.pop();
			B++;
		}else if(A<=T){
			dict.push(A++);
		}else{
			ok=0;break;
		}
	}
	//清空栈 
	while(dict.size()) dict.pop();
	printf("%s\n",ok?"Yes":"No");		 

}
	cout<<endl;

}
}
