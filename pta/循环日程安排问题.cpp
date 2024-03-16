// 循环日程安排问题
#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;

const int maxn = 1e5 + 5;

int a[11514][11514];
void solve( int num ){
    if( num == 1 ){
        a[1][1] = 1;
        return ;

    }else if(num == 2){
        a[1][1] = 1;    a[1][2] = 2;
        a[2][1] = 2;    a[2][2] = 1;
    } else {
        solve( num/2 );
        //复制到右下角
        int index = (num/2);
        for( int i = 1; i <= num/2; i ++ ){
            for( int j = 1; j <= num/2; j++ ){
                a[index + i][index + j] = a[i][j];
                a[index + i][j] = a[i][j] + index;
                a[i][index + j] = a[i][j] + index;
            }
        }
        //复制到右上 和 左下
    
    }
}

int main() 
{ 
    clock_t c1 = clock();
    freopen("in.in","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
    freopen("out.out","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    

    int k;
    cin >> k;
    
    int num = pow(2, k);
    solve( num );
    for( int i = 1; i <= num; i++ ){
        for( int j = 1; j <= num; j++ ){
            cout<<a[i][j]<<" ";
        }
        if( i != num )cout<<endl;
    }



    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
    return 0; 
}

