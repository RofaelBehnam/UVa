#include <stdio.h>
#include <math.h>
//Binary Search
long long length[45001],i, key, ret;

int BinarySearch(int Low, int High){
	if(Low>High)
		return High;
	int Mid=(Low+High)/2;
	if(length[Mid]==key)
		return Mid;
	if(length[Mid]>key)
		return BinarySearch(Low, Mid-1);
	if(length[Mid]<key)
		return BinarySearch(Mid+1, High);

}

void count(){
	long long temp=length[ret], num, k;
	for(int j=1;j<=ret+1;j++){
		num=ceil(log10(j+1));
		temp+=num;
		if(temp>=key){
			temp-=num;
			k=ceil(log10(j+1))-1;
			while(temp<key){
				num=(j%(long long)pow10(k+1)-j%(long long)pow10(k))/(long long)pow10(k);
				temp++;
				k--;
			}
			printf("%lld\n", num);
			return;
		}
	}
}
int main(){
	length[0]=1;
	for(i=2;i<45000;i++){
		length[i-1]=length[i-2]+(long long)ceil(log10(i+1));
	}
	for(i=1;i<45000;i++){
		length[i]+=length[i-1];
		if(length[i]<0)
			break;
	}
	int N;
	scanf("%d",&N);
	for(int j=0;j<N;j++){
		scanf("%lld", &key);
		ret = BinarySearch(0,i);
		if(length[ret]==key)
			printf("%lld\n", ret+1);
		else
			count();
	}
	return 0;
}
