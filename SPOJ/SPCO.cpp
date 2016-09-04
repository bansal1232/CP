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
typedef unsigned long long ULL;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<string,string> pss;
typedef pair<int,double> pid;
typedef pair<int,LL> pil;
typedef pair<LL,LL> pll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SYNC ios_base::sync_with_stdio(false)
#define TIE cin.tie(0)
#define INF 1000000000
#define INFLL 4000000000000000000LL
#define EPS 1e-9
#define MOD 1000000007LL
#define DEBUG puts("DEBUG")

#ifdef _WIN32
#define getchar_unlocked getchar
#endif

#define g getchar_unlocked

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

ULL nCk[70][70];
ULL a,b;
int tc;
int arr[75];
bool flag[75];

vector<int> prime;
inline void Generate(){
 flag[0]=flag[1]=1;
 for(int i=2;i<=70;i++)
  if(!flag[i]){
   prime.pb(i);
   for(int j=i;j<=70/i;j++)
    flag[i*j]=1;
   } 
 for(int i=0;i<=64;i++)
  nCk[i][0]=1;
 for(int i=1;i<=64;i++)
  for(int j=1;j<=i;j++)
   nCk[i][j]=nCk[i-1][j-1]+nCk[i-1][j];   
}


inline ULL calc(ULL x){
 int it=0;
 while(x){
  arr[it]=x&1;
  x>>=1;

  it++;
 }
 ULL ret=0;
 int sum=0;
 for(int i=it-1;i>=0;i--)
  if(arr[i]){
   //sum++;
   int pos=lower_bound(prime.begin(),prime.end(),sum)-prime.begin();
   //printf("%d %d\n",sum,prime[pos]);
   for(int j=pos;j<prime.size();j++){
    int y=prime[j];
    if(prime[j]-sum>i) break;
    ret+=nCk[i][prime[j]-sum];
    //printf("%d %d\n",prime[j],sum);
   }
   sum++;
  }
 ret+=(!flag[sum]); 
 return ret; 
}

int main(){
 Generate();
 scanf("%d",&tc);
 while(tc--){
  scanf("%llu %llu",&a,&b);
  printf("%llu\n",calc(b)-calc(max((ULL)0,a-1)));
 }
 //puts("ganteng");
 return 0;
}

