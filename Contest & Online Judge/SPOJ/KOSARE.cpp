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
#define MOD 1000000007
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

int power[1000005];
int cnt[(1<<20) + 5];
int n,m,a,b;

inline void add(int &x,int y){
 x+=y;
 if(x>=MOD) x-=MOD;
 if(x<0) x+=MOD;
}

void rec(int l,int r){
 if(l+1==r){ // base case 
  cnt[l]=power[cnt[l]]; // banyak subset submasknya
  return;
 }
 int mi=(l+r)>>1;
 for(int i=l;i<mi;i++)
  cnt[mi+i-l]+=cnt[i]; // banyak submasknya
 rec(l,mi);
 rec(mi,r);
 for(int i=l;i<mi;i++){ // cnt udah jadi banyak subset, delete subset yang kalo di or gak jadi mi+i-l 
  cnt[mi+i-l] -= cnt[i];
  if(cnt[mi+i-l] < 0) cnt[mi+i-l]+=MOD;
 }
}

int main(){
 n=io(),m=io();
 power[0]=1;
 for(int i=1;i<=n;i++){
  power[i]=power[i-1]<<1;
  if(power[i] >= MOD) power[i]-=MOD;
 }
 for(int i=0;i<n;i++){
  int mask=0;
  a=io();
  while(a--){
   b=io();
   mask|=(1<<(b-1));
  }
  cnt[mask]++;
 } 
 rec(0,1<<m);
 cout<<cnt[(1<<m) - 1]<<"\n";
 //puts("ganteng");
 return 0;
}
