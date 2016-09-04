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

char x[5005];
bool dp[35][35][6001];
vector<pair<int,pii> > vis;
vector<int> ang,op;
int ans;

void rec(int idx,int open,int val){
 if(dp[idx][open][val]) return;
 dp[idx][open][val]=1;
 vis.pb(mp(idx,mp(open,val)));
 if(idx==(int)ang.size()){
  if(open) rec(idx,0,val);
  else ans++;
  return;
 }
 int nval;
 nval=val+(open&1 ? -1 : 1)*op[idx]*ang[idx];
 rec(idx+1,open,nval);
 if(open) rec(idx+1,open-1,nval);
 if(op[idx]==-1) rec(idx+1,open+1,nval);
}

int main(){
 while(gets(x)){
  ans=0;
  while(!vis.empty()){
   pair<int,pii> lol=vis.back();
   vis.pop_back();
   dp[lol.fi][lol.se.fi][lol.se.se]=0;
  }
  ang.clear();
  op.clear();
  op.pb(1);
  int len=strlen(x);
  int tot=0;
  for(int i=0;i<len;i++){
   if(x[i]>='0' && x[i]<='9')
    tot=tot*10 + x[i]-'0';
   else if(x[i]=='+')
    op.pb(1);
   else if(x[i]=='-')
    op.pb(-1);
   else if(x[i-1]>='0' && x[i-1]<='9')
    ang.pb(tot),tot=0;    
  }
  ang.pb(tot);
  rec(0,0,3000);
  printf("%d\n",ans);
 }
 //puts("ganteng");
 return 0;
}

