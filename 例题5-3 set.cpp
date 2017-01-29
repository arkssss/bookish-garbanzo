#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <sstream>
using namespace std;

set<string> dict;

int main (){
	
	string s,buf;
	while(cin>>s){

	for(int i=0;i<s.length();i++){
		
			if(isalpha(s[i])){
				s[i]=tolower(s[i]);
			}else{
				s[i]=' ';
			}	

	}
	
	//此时的ss有可能两边有空格 所以创建成字符流消除 
	stringstream ss(s);

	while(ss>>buf){
		
		dict.insert(buf);	
			
	}
	
	}	


	for(set<string>::iterator it=dict.begin();it!=dict.end();it++){
	
		cout<<*it<<'\n';
	
	} 
	return 0;





}
