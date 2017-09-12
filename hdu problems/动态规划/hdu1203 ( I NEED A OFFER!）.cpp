#include <iostream>
#include <cstring>
int N,M;
int i,j;
double m;
int w[10010];
double v[10010],dp[10010];
const double& max_(const double &a,const double &b){
if(a<b)
return b;
else return a;
}
int main(){
while(std::cin>>N>>M&&N+M){
for(i=0;i<M;++i){
std::cin>>w[i]>>v[i];
}
memset(dp,0,sizeof(dp));
for(i=0;i<M;++i){
    for(j=N;j>=w[i];--j){
       dp[j]=max_(dp[j],1-(1-v[i])*(1-dp[j-w[i]]));
      }
    }
m=dp[N]*100;
 printf ("%.1lf%%\n", m);
  }
}