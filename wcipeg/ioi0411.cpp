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

int dpx[2][2005],dpy[2][2005];
int n;

int main(){
 for(int i=0;i<2;i++)
  for(int j=0;j<=2000;j++)
   dpx[i][j]=dpy[i][j]=INF;
 dpx[0][1000]=dpy[0][1000]=0;
 int lasx=1000,lasy=1000;
 SYNC;
 cin>>n;
 for(int i=1;i<=n;i++){
  int a,b;
  cin>>a>>b;
  a+=1000,b+=1000;
  int bit=i&1;
  int mx=INF,my=INF;
  for(int j=0;j<=2000;j++){
   my=min(my,dpy[bit^1][j] + abs(a-j));
   mx=min(mx,dpx[bit^1][j] + abs(b-j));
  }
  int m1x=INF,m1y=INF;
  for(int j=0;j<=2000;j++){ 
   dpx[bit][j]=min(dpx[bit^1][j]+abs(a-lasx),my + abs(j-lasy));
   dpy[bit][j]=min(dpy[bit^1][j]+abs(b-lasy),mx + abs(j-lasx));
   m1x=min(m1x,dpx[bit][j]);
   m1y=min(m1y,dpy[bit][j]);
  }
  //cout<<m1x<<" "<<m1y<<"\n";
  lasx=a,lasy=b;
 }
 int ans=INF;
 int bit=n&1;
 for(int i=0;i<=2000;i++){
  ans=min(ans,dpx[bit][i]);
  ans=min(ans,dpy[bit][i]);
 }
 cout<<ans<<"\n";
 //puts("ganteng");
 return 0;
}

