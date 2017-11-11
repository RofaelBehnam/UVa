#include <stdio.h>
//Number Theory
long long Power3[10001];
int Diff[10001][2];
int main(){
	int i=1,j,k;
	Power3[0]=0;
	while(i*i*i-Power3[i-1]<=10000){
		Power3[i]=i*i*i;
		i++;
	}
	for(j=0;j<=10000;j++)
		Diff[j][0]=Diff[j][1]=-1;
	for(j=0;j<i;j++){
		for(k=0;k<j;k++){
			if(Power3[j]-Power3[k]<=10000 && (Diff[Power3[j]-Power3[k]][0] == -1 || k<Diff[Power3[j]-Power3[k]][1])){
				Diff[Power3[j]-Power3[k]][0]=j;
				Diff[Power3[j]-Power3[k]][1]=k;
			}

		}
	}
	long long N;
	scanf("%lld", &N);
	while(N!=0){
		if(Diff[N][0]!=-1){
			printf("%d %d\n",Diff[N][0],Diff[N][1]);
		}else{
			printf("No solution\n");
		}
		scanf("%lld", &N);
	}
	return 0;
}
