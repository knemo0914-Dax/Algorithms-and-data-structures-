#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"This program automically displays prime numbers from 2 - n"<<endl;
	cout<<"Enter a value for n: ";
	cin>>n;
	if(n>=2){
		cout<<"The prime numbers for this (2:"<<n<<"): ";
		for(int i=2;i<=n;i++){
			bool isprime=true;
			
			for(int j=2;j<i;j++){
				if(i%j==0){
					isprime=false;
					break;
				}
			}
			if(isprime){
				cout<<i<<", ";
			}
			
		}
	}else if(n==0 || n==1){
		cout<<"--- "<<n <<" is not a prime number ---"<<endl;
	}else{
		cout<<"Negative prime numbers don't exists.";
	}
	return 0;
}

