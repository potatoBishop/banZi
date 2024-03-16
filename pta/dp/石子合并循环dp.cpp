#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int INF = 0x7f7f7f7f;

int b[2010][2010];
int a[2010][2010];
int sum[2010];
int stone[2010];
int n;
void dp( ){
    for( int len = 1; len < n; len++ ){
        for( int i = 1; i <= (2*n - len); i++ ){
            int j = i+len;
            int temp = sum[j] - sum[i-1];
            for( int k = i; k < j; k++ ){
                a[i][j] = min( a[i][j], a[i][k]+a[k+1][j]+temp );
                b[i][j] = max( b[i][j], b[i][k]+b[k+1][j]+temp );   
            }
        }
    }
   
}

int main(){
    cin >> n;
    memset(a, INF, sizeof(a));
    memset(b,  0, sizeof(b));
    
    for( int i = 1; i <= n; i++ ){
        cin >> stone[i]; 
        stone[i+n] = stone[i];
    } 
    for (int i = 1; i <= 2*n; i ++ ) {
        a[i][i] = 0;
        b[i][i] = 0;
        sum[i]  = sum[i-1] + stone[i];
    }
    
    dp();
    
    int p = 0x7f7f7f7f;
    for( int i = 1; i <= n; i++ ){
        p = min( p, a[i][i+n-1] );
    }cout<<p<<endl;
    
    p = 0;
    for( int i = 1; i <= n; i++ ){
        p = max( p, b[i][i+n-1] );
    }cout<<p;
    
    return 0;
}




