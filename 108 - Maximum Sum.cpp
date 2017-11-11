#include<stdio.h>
int arr[100][100];
long long dp[100][100];
long long ret=-100*127*100;
int main(){
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d", &arr[i][j]);
				dp[i][j]=arr[i][j];
				if(i>0)
					dp[i][j]+=dp[i-1][j];
				if(j>0)
					dp[i][j]+=dp[i][j-1];
				if(i>0&&j>0)
					dp[i][j]-=dp[i-1][j-1];
			if(ret<dp[i][j])
				ret = dp[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=i;k<N;k++){
				for(int l=j;l<N;l++){
					if(i==1&&j==0&&k==3)
						i=1;
					int tmp=dp[k][l];
					if(i>0)
						tmp-=dp[i-1][l];
					if(j>0)
						tmp-=dp[k][j-1];
					if(i>0&&j>0)
						tmp+=dp[i-1][j-1];
					if(tmp>ret)
						ret=tmp;
				}
			}
		}
	}
	printf("%lld\n", ret);
	return 0;
}
