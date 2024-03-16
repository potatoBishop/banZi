#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;


int dp[1010][1010];
int R, temp;

int main() 
{   
    //=======================================================================================
    clock_t c1 = clock();
    freopen(  "in.in", "r", stdin); //输入重定向，输入数据将从in.txt文件中读取
    freopen("out.out", "w",stdout); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    memset(dp, 0, sizeof(dp));
    cin >> R;
    for( int i = 1; i <= R; i++ ){
        for( int j = 1; j <= i; j++ ){
            cin >> temp;
            dp[i][j] = temp;
            if(   dp[i-1][j] > 0 ) dp[i][j] = max( dp[i][j],   dp[i-1][j] + temp );
            if( dp[i-1][j-1] > 0 ) dp[i][j] = max( dp[i][j], dp[i-1][j-1] + temp );
            // cout<<dp[i][j]<<" ";            
        }
        // cout<<endl;
    }
    int mm = 0x80000000;
    for( int i = 1; i <= R; i++ ){
        mm = max( dp[R][i], mm );
    }
    cout<<mm;



   

    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
    //=======================================================================================
    
    return 0; 
}

