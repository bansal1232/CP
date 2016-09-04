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

vector<int> adj[105];
int deg[105];
int tc,n,m;

inline void Topo(){
 priority_queue<int> pq;
 for(int i=1;i<=n;i++)
  if(deg[i]==0)
   pq.push(-i);
 bool spasi=0;
 while(!pq.empty()){
  int id=-pq.top(); pq.pop();
  if(spasi) cout<<" ";
  else      spasi=1;
  cout<<id;
  for(int i=0;i<adj[id].size();i++){
   int nxt=adj[id][i];
   deg[nxt]--;
   if(deg[nxt]==0) pq.push(-nxt);
  }
  adj[id].clear();
 } 
 cout<<"\n"; 
}

int main(){
 SYNC;
 cin>>tc;
 while(tc--){
  cin>>n>>m;
  while(m--){
   int a,b;
   cin>>a;
   cin>>deg[a];
   for(int i=0;i<deg[a];i++)
    cin>>b,adj[b].pb(a);
  }
  Topo();
  if(tc)
   cout<<"\n";
 }
 //puts("ganteng");
 return 0;
}

