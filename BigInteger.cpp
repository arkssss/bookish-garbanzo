//大整数类 Big Integer 
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
struct BigInteger{
	
	static const int BASE=100000000;
	static const int WIDTH=8;
	vector <int> s;

	//构造函数 
	BigInteger (long long num=0){
		*this =num;
	}
	
	//重载与Long long 类型的=运算符号
	BigInteger operator = (long long num){
		s.clear();	
		do{
		
			
			s.push_back(num%BASE);
			num/=BASE;


	
		}while(num>0);
	
		return *this;	
	
	} 


	//重载与string类型的=符号

	BigInteger operator =(const string &str){
		s.clear();	
	
		int x,len=(str.length()-1)/WIDTH+1;
		for(int i=0;i<len;i++){
			int end=str.length()-i*WIDTH;
			int start =max(0,end-WIDTH);

			sscanf(str.substr(start,end-start).c_str(),"%d",&x);
	
			s.push_back(x);
		}	
		return *this;

		
	} 



};


int main (){
	


	string s1="1231231423543635654634324324";
	
	BigInteger x ;

	x=s1;


	for(vector<int>::iterator it=x.s.begin();it!=x.s.end();it++){
		cout<<*it;
	}









}
