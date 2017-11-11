#include <stdio.h>
#include<string.h>
int dp[15][82][82][2];
char s[20];
int T, k,ans;
long long A,B;
//Dynamic Programming
int calc(int dep, int num, int dig, bool flag){
	if(dep==strlen(s)){
		if(num%k==0 && dig%k ==0)
			return 1;
		return 0;
	}
	if(dp[dep][num][dig][flag]!=-1)
		return dp[dep][num][dig][flag];
	int ret=0,t=s[dep]-'0';
	for(int i=0;i<10;i++){
		if(flag==true && i>t) break;
		ret+=calc(dep+1, (num*10+i)%k, (dig+i)%k, i<t?0:flag);
	}
	return dp[dep][num][dig][flag]=ret;
}

void reset(){
	for(int i=0;i<15;i++){
		for(int j=0;j<82;j++){
			for(int k=0;k<82;k++){
				for(int l=0;l<2;l++){
					dp[i][j][k][l]=-1;
				}
			}
		}
	}
}
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%lld%lld%d", &A,&B, &k);
		if(k>82)
			ans=0;
		else{
			if(k==1)
				ans = B-A+1;
			else{
				reset();
				sprintf(s,"%lld",A-1);
				int a = calc(0,0,0,1);
				reset();
				sprintf(s,"%lld",B);
				int b = calc(0,0,0,1);
				ans = b-a;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
