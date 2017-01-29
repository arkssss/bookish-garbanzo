/*
MTA London 4 Fiona Paul Heather Nevil
MTA SanFrancisco 3 Mario Luigi Shariff
MTA Paris 3 Jacque Suzanne Maurice
MTA HongKong 3 Chen Jeng Hee
MTA MexicoCity 4 Conrado Estella Eva Raul
MTA Cairo 3 Hamdy Tarik Misa
*
Hamdy@Cairo Conrado@MexicoCity Shariff@SanFrancisco Lisa@MexicoCity
*
Congratulations on your efforts !!
--Hamdy
*
Fiona@London Chen@HongKong Natasha@Paris
*
Thanks for the report! --Fiona
*
*


*/
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>

using namespace std;

void parse_address(const string& s,string &user,string &mta){
	
	int k=s.find('@');
	user=s.substr(0,k);
	mta=s.substr(k+1);

}

int main (){
	
	freopen("input.txt","r",stdin);	
	string s,t,user1,mta1,user2,mta2;
	int k;
	set<string> addr;
	
	//处理addr 
	while(cin>>s && s!="*"){
	
		cin>>s>>k;
		while(k--){
			
			cin>>t;
			addr.insert(t+"@"+s);		
	
		}

	} 


	
	while(cin>>s && s!="*"){
	
		
	parse_address(s,user1,mta1);
		
		

	vector<string> mta;
	//收信人 
	set<string> vis;
	map<string ,vector<string> > dist; 


	while(cin>>s &&s!="*"){

		//收信人重复 
	  	if(vis.count(s)) continue;

	    parse_address(s,user2,mta2);
		vis.insert(s);
		
		if(!dist.count(mta2)) {
		
			mta.push_back(mta2);
			dist[mta2]=vector<string>();
				
		}	
			dist[mta2].push_back(s);
			
	}




	//消除* 
	getline(cin,t);	
	
	string data;
	while(getline(cin,t) && t[0]!='*') data+="	"+t+'\n';


	for(int i=0;i<mta.size();i++){
		
		string mta2=mta[i];
		string s="Connection between "+mta1+" and "+mta2;
		cout<<s<<'\n';
		cout<<"HELO"<<mta1<<'\n'<<"250\n";
		cout<<"MAIL FROM:<"<<user1<<'@'<<mta1<<">\n"<<"250\n";

		bool ok=0;
		int k=dist[mta2].size();
		for(int i=0;i<k;i++){

		s=dist[mta2][i];
		cout<<"RCPT TO:<"<<s<<">\n";


		if(addr.count(s)){
		
			cout<<"250\n";	
			ok=1;

		}else{
			cout<<"550\n";
		}

		

		}
		if(ok){
		
		cout<<"DATA"<<"\n"<<"354\n";
		cout<<data<<".\n"<<"250"<<'\n';
		
		}

		cout<<"QUIT\n221\n";



	
      	} 




	}






	return 0;







}


