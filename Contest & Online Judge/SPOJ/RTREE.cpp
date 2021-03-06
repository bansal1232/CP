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

int Path[100005], Dia[100005];
int n,q;
vector<int> adj[100005];
int u,v,root;

void dfs(int prev,int now){
 int best=-1,best2=-1;
 int lol=0;
 for(int i=0;i<adj[now].size();i++){
  int nxt=adj[now][i];
  if(nxt!=prev){
   dfs(now,nxt);
   lol=max(lol,Dia[nxt]);
   if(Path[nxt] > best2) best2=Path[nxt];
   if(best2 > best) swap(best2,best);
  }
 }
 Path[now]=best+1;
 lol=max(lol,best+best2+2);
 Dia[now]=lol;
 //printf("%d %d %d\n",now,Dia[now],Path[now]);
}

int main(){
 scanf("%d",&n);
 for(int i=1;i<n;i++){
  scanf("%d %d",&u,&v);
  adj[u].pb(v);
  adj[v].pb(u);
 }
 scanf("%d",&root);
 dfs(0,root);
 scanf("%d",&q);
 while(q--){
  scanf("%d",&u);
  printf("%d\n",Dia[u]);
 }
 //puts("ganteng");
 return 0;
}
