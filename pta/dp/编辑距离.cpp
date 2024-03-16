#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e3 + 5;
int n;

int halfSolve(string a, string b, int sizea, int sizeb){
    int dp[sizea+10][sizeb+10];
    memset(dp, 0, sizeof(dp));
    for( int i = 1; i <= sizea; i++ )
        dp[i][0] = i;

    for( int j = 1; j <= sizeb; j++ )
        dp[0][j] = j;
    
    for( int i = 1; i <= sizea; i++ ){
        for( int j = 1; j <= sizeb; j++ ){
            if( a[i] == b[j] ) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j-1]+1;

            dp[i][j] = min( dp[i][j], min( dp[i][j-1]+1, dp[i-1][j]+1 ) );
        }
    }
    return dp[sizea][sizeb];
}

int main() 
{ 
    clock_t c1 = clock();
    freopen(   "in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    string a,b;
    cin >> a >> b;
    int sizea = a.length();
    int sizeb = b.length();
    a = " "+a;
    b = " "+b;

    int same = halfSolve(a, b, sizea, sizeb);
    cout<<same-1<<endl;



    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}

