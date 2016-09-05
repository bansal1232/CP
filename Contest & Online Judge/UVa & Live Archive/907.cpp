#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
#include <cassert>
#define makmu using
#define ndasmu namespace
#define gundulmu std

makmu ndasmu gundulmu;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<string,string> pss;
typedef pair<int,double> pid;
typedef pair<int,LL> pil;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SYNC ios_base::sync_with_stdio(false)
#define g getchar_unlocked
#define INF 1000000000
#define INFLL 4000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
#define DEBUG puts("DEBUG")


int dx8[8]={-1,-1,0,1,1,1,0,-1},dx4[4]={-1,0,1,0};
int dy8[8]={0,-1,-1,-1,0,1,1,1},dy4[4]={0,-1,0,1};

inline void open(string name){
 freopen((name+".in").c_str(),"r",stdin);
 freopen((name+".out").c_str(),"w",stdout);
}

inline void close(){
 fclose(stdin);
 fclose(stdout);
}

inline int io(){
 register char c;
 while(1){
  c=g();
  if(c!='\n' && c!=' ') break;
 }
 int res=0,sign=1;
 if(c=='-') sign=-1;
 else       res=c-'0';
 while(1){
  c=g();
  if(c==' ' || c=='\n' || c==EOF) break;
  res=(res<<3)+(res<<1)+c-'0';
 }
 return res*sign;
}

///////////////////////////////////////////////////
//////            End of Template            /////
/////////////////////////////////////////////////

int dp[605][305];
int n,k;
int arr[605];

inline void reset(){
 for(int i=0;i<=n;i++)
  for(int j=0;j<=k;j++)
   dp[i][j]=-1;
}

int solve(int pos,int left){
 if(pos>n) return 0;
 else if(left==-1) return INF<<1;
 else if(dp[pos][left]!=-1) return dp[pos][left];
 else{
 int ret=INF<<1;
 int sum=0;
 for(int i=pos;i<=n;i++){
   sum+=arr[i];
   if(sum>ret) break;
   ret=min(ret,max(sum,solve(i+1,left-1)));
  }
 //printf("DP %d %d VAL %d\n",pos,left,ret); 
 return dp[pos][left]=ret; 
 }
}

int main(){
 while(scanf("%d %d",&n,&k)==2){
  reset();
  for(int i=0;i<=n;i++)
   scanf("%d",&arr[i]);
  printf("%d\n",solve(0,k)); 
 }
 //puts("ganteng");
 return 0;
}
