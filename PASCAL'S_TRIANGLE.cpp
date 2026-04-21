#include<iostream>
using namespace std;
int main(){
	int n;
	// longer rows 25 will output sometime scattered
	cout<<"Enter the number of rows: "<<endl;
	cin>>n;
	long long arr[100][100];
	for (int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			if(j==0||j==i){
				arr[i][j]=1;
			}
			else{
				arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
			}
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

