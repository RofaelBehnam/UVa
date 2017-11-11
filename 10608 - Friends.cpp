#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;
long long parent[10000001];
int getParent(int i){
	return parent[i]==i?i:(parent[i]=getParent(parent[i]));
}

int T, S, e, i;
long long counter[10000000];
int main(){
	cin  >> T;
	while(T--){
		cin >> e;
		for(i=1;i<=e;i++){
			parent[i]=i;
			counter[i]=0;
		}
		long long v1,v2;
		cin >> S;
		for(i=1;i<=S;i++){
			cin >> v1 >> v2;
			parent[getParent(v1)]=getParent(v2);
		}
		for(i=1;i<=e;i++)
			counter[getParent(i)]++;
		long long mx=0;
		for(i=1;i<=e;i++){
			if(counter[i]>mx)
				mx=counter[i];
		}
		cout << mx << endl;
	}
	return 0;
}
