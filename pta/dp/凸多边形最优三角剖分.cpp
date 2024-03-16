 凸多边形最优三角剖分
 #include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;
int a[10][10];


int solve(int n ){
    int dp[n+10][n+10];
    memset(dp, 0, sizeof(dp));

    for( int r = 3; r <= n; r++ ){                // 点的个数[3, 7]
        for( int i = 1; i <= n-r+1; i++ ){        //  i范围[1, n-2]
        // for( int i = n-r+1; i >=1 ; i-- ){        //  i范围[1, n-2]
            int j = i+r-1;                        //  j范围[3,   n]
            // 初始化dp数组
            // if( i == 4 && j == 6 ) cout<<a[i][i+1]<<" "<<a[i][j]<<" "<<a[i+1][j]<<endl;;
            // dp[i][j] = dp[i][i+1] + dp[i+1][j] + a[i][i+1] + a[i][j] + a[i+1][j];
            // cout<<i<<" "<<j<<endl;
            for( int k = i+1; k < j; k++ ){
                int temp = dp[i][k] + dp[k][j] + a[i][k] + a[k][j] + a[i][j];
                // if( temp < dp[i][j] ) dp[i][j] = temp; 
                if( dp[i][j] == 0 ) dp[i][j] = temp; 
                else dp[i][j] = min( dp[i][j],  temp);
                
            }
        }
    }

    for( int i = 1; i <= n; i++ ){
        for( int j = 1; j <= n; j++ ){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[1][n];
}

int main() 
{ 
    clock_t c1 = clock();
    freopen(   "in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    int n;
    cin >> n;

    // 处理输入
    
    for( int i = 1; i <= n; i++ ){
        for( int j = i; j <= n; j++ ){
            cin >> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    //
    cout << solve(n);
    
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}

