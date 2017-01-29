/*
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1
*/
#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm> 
#include <vector>
#include <queue>
using namespace std;

int main (){
//	freopen("i.txt","r",stdin);		
//	freopen("o.txt","w",stdout); 
	//vector用于存放输入的优先级的种类	
	vector<int> Priority;	
	//key job 的位置信息 value job的优先级 
	map<int,int> dict;	
	int Tot,n,pos,pri;
	scanf("%d",&Tot);

	for(int k=0;k<Tot;k++){
		//工作队列 
		queue<int> job;	
		scanf("%d%d",&n,&pos);
			for(int i=0;i<n;i++){
				scanf("%d",&pri);
				job.push(i);
				dict[i]=pri;		
				Priority.push_back(pri);
			}
		sort(Priority.begin(),Priority.end());
		int countTimes=0;
		vector<int>::reverse_iterator it=Priority.rbegin();
			for(;;){
				int PersentPri=*it;		
				int PreJob=job.front();
				//最前的元素的优先级小于最大优先级 
				if(dict[PreJob]<PersentPri){
					job.pop();
					job.push(PreJob);	
				}else{
					job.pop();
					it++;	
					countTimes++;
					if(PreJob==pos) break;
				}
					
			}
		cout<<countTimes<<endl;
		Priority.clear();
		dict.clear();
		
}	


	return 0;


} 
