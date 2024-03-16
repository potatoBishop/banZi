#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;

int r[1010];
int m[1010][1010];
int flag[1016][1016];
int p, num = 0, n;

void fin( int i, int j ){
    if( i == j ) cout<<"A"<<i;
    else {
        cout<<"(";
        fin(i, flag[i][j]);
        fin(flag[i][j]+1, j);
        cout<<")";
    }
}

void solve(){
    for( int i = 1; i<= n; i++ ) m[i][i] = 0; //初始化存放min值的数组

    for( int len = 2; len <= n; len++ ){      //长度范围
        for( int i = 1; i <= n-len+1; i++ ){    //起始点
            int j = i+len-1;                    //结束点
            m[i][j] = r[i-1]*r[i]*r[j] + m[i+1][j];
            flag[i][j] = i;
            for( int k = i+1; k <= j-1; k++ ){
                int t = m[i][k] + m[k+1][j] + r[i-1]*r[k]*r[j];
                if( t < m[i][j] ) {
                    m[i][j] = t;
                    flag[i][j] = k;
                }
            }
        }
    }
    cout<<m[1][n]<<endl;
    fin(1, n);
}

int main() 
{ 
    clock_t c1 = clock();
    freopen(   "in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    int u;
    cin >> u;
    getchar();
    while( u-- ){
        string str;
        stringstream sstream;
        getline(cin, str);
        sstream << str;
        while( sstream >> p ){
            r[num] = p;
            num ++;
        }
        n = num - 1;    /*矩阵数量*/
        solve();
        if(u != 0)cout<<endl;
    }
    

    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
    return 0; 
}

