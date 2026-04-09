#include<iostream>
using namespace std;
int main(){
	int n;
	cout<<"This program automically displays prime numbers from 0 - n"<<endl;
	cout<<"Enter a value for n: ";
	cin>>n;
	if(n>=0){
		cout<<"The prime numbers for this (0:"<<n<<"): ";
		for(int i=0;i<=n;i++){
			if(i%2 == 1){
				cout<<i<<", ";
			}
		}
	}else{
		cout<<"Negative prime numbers don't exists.";
	}
	return 0;
}

