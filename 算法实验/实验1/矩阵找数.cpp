#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;

void solve(){
    int n, m;
    cin >> n >> m;
    int ** a = new int*[n+1];
    int *p;
    for( int i = 1; i <= n; i++ ){
        p = new int[n+1];
        for( int j = 1; j <= n; j++ ){
            cin>>p[j];
        }
        a[i] = p;
    }
    // cout<<" ============="<<endl;

    int row = 1;
    int col = n;
    int flag = 0;
    while( row <= n && col >= 1 ){
        // cout<<row<<" "<<col<<endl;
        if( a[row][col] < m ){
            row++;
        } else if( a[row][col] > m  ){
            col--;
        } else{
            flag = 1;
            break;
        }
    }
    if( flag == 1 )cout<<"true"<<endl;
    else cout<<"false"<<endl;

    for( int i = 1; i <= n; i++ ){
        free( a[i] );
    }
    free(a);

    return;
}

int main() 
{ 
    clock_t c1 = clock();
    freopen(   "E:\\VS_code\\C++\\in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "E:\\VS_code\\C++\\out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    int T ;
    cin >> T;
    while( T-- ){
        solve();
    }
   
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}

