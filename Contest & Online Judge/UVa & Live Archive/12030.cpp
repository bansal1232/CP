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

//0 : butuh 2
//1 : aman
//2 : super aman

LL dp[3][1 << 15];
int arr[20][20];
int tc,n;

LL DP(){
    dp[1][0] = 1;
    for(int i = 0 ; i + 1 < (1 << n) ; i++)
        for(int j = 0 ; j < 3 ; j++)
            if(dp[j][i]){
                int idx = __builtin_popcount(i);
                for(int k = 0 ; k < n ; k++)
                    if((i & (1 << k)) == 0){
                        int nxt = i | (1 << k);
                        if(arr[idx][k] == 0)
                            dp[j == 2 ? 2 : 0][nxt] += dp[j][i];
                        else if(arr[idx][k] == 1)
                            dp[j][nxt] += dp[j][i];
                        else
                            dp[2][nxt] += dp[j][i];       
                    }
            }
   int last = (1 << n) - 1;
   return dp[1][last] + dp[2][last];         
}

int main(){
 scanf("%d",&tc);
 for(int t = 1 ; t <= tc ; t++){
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            scanf("%d",&arr[i][j]);
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < (1 << n) ; j++)
            dp[i][j] = 0;
    printf("Case %d: %lld\n",t,DP());                
 }
 //puts("ganteng");
 return 0;
}

