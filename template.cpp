#include <iostream>
using namespace std;

	template<typename T>
	struct Point{
	
		T x,y;
		Point (T x=0,T y=0):x(x),y(y){}
		


	};
		

	template<typename T>
	Point<T> operator + (const Point<T>& A,const Point<T>& B){
	
		return Point<T>(A.x+B.x,A.y+B.y);



	}

		// ostream& 为返回类型 
	template<typename T>
	ostream& operator <<(ostream &out,const Point<T>& p){
	
			
		out << "(" <<p.x<<","<<p.y<<")";

		return out;	


	}

		
		template<typename T>
		T sum(T *begin,T*end){
			
			T *p=begin ;
		
			T ans=0;
			
			for(T *p=begin;p!=end;p++){
			
				ans= ans + *p;
		
		
			}
		
		
			return ans;
		
		}



 int main() {
	

		Point<double> a(1.1,2.2),b(2.2,3.3);
		Point<int> c(2.3),d(1,2);

		//cout<<b.x;		 


	   cout<<a+b<<" "<<c+d; 

 }
