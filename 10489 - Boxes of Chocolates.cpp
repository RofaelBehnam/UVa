#include <stdio.h>
#include<iostream>
using namespace std;
int T,N,B,K,a,i,j,l,result;
int main() {
	cin >> T;
	for(i=0;i<T;i++){
		cin >> N >> B;
		result=0;
		for(j=0;j<B;j++){
			cin >> K;
			int temp=1;
			for(l=0;l<K;l++){
				cin >> a;
				temp*=a%N;
				temp%=N;
			}
			result+=temp;
			result%=N;
		}
		cout << result << endl;
	}
	return 0;
}
