#include <cstdio>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
const int maxt=1000;

int main (){
		
	freopen("input.txt","r",stdin);

	//team的数量 
	int t,count=0;
	while(scanf("%d",&t)==1 && t){
	cout<<"Scenario #"<<++count<<'\n';
	map <int,int> team;
	for(int i=0;i<t;i++){
	int size,num;
	scanf("%d",&size);	
	while(size--){
		scanf("%d",&num);
		team[num]=i; 
		}			

	} 
	queue<int> q,q2[maxt]; 
	for(;;){
	string cmd;
	cin>>cmd;
	if(cmd[0]=='S') break;

	//入列 
	if(cmd[0]=='E'){

		int cmd_num;
		cin>>cmd_num;
		//寻找team 
		int t=team[cmd_num];
		//如果为空			 
	if(q2[t].empty()){
		
		q.push(t);			
	}
	q2[t].push(cmd_num);

	continue;


	}
	//出列 
	if(cmd[0]=='D'){
	
		int t=q.front();
		cout<<q2[t].front()<<'\n';		
		q2[t].pop();
		if(q2[t].empty()){
			q.pop();
		}
		
		continue;

	}	

}
}
}
