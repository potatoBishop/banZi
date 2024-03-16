#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<sstream>
using namespace std;
const int maxn = 1e5 + 5;

int* getg( int* a, int* b ){//返回前缀和数组
    int size = a[0]+b[0];
    int* reg = new int[size + 2];
    reg[0] = size;
    for( int i = 1; i <= a[0]; i++  ){
        reg[i] = a[i];
    }

    for( int i = 1; i <= b[0]; i++ ){
        reg[i+a[0]] = reg[a[0]] + b[i];
    }
    return reg;
}

int str[200010][11];

int jian( int*a, int* b ){
    if( a[0] != b[0] ) return 0;
    for( int i = 1; i <= a[0]; i++ ){
        if( a[i] != b[i] ){ return 0; }
    }
    return 1;
}

void solve( ){
    int n;
    long long num = 0;
    
    string pstr;
    cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> pstr;
        int end = pstr.length();
        for( int j = 0; j < end; j++  ){
            str[i][j+1] = pstr[j] - '0';
            str[i][j+1] += str[i][j];
            // cout<< str[i][j+1] <<" "; 
        }
        str[i][0] = pstr.length();
        // cout<<endl;
    }
    for( int i = 1; i <= n; i++ ){
        for( int j = i; j <= n; j++ ){
            if( jian(str[i], str[j]) && i == j ){
                // cout<<i<<"==="<<j<<endl;
                num++;
            } else{
                int* res1 = getg(str[i], str[j]);
                int* res2 = getg(str[j], str[i]);
                int endid = res1[0];
                if( endid%2 == 0 ){
                    // cout<<i<<"==="<<j<<endl;
                    // for( int k = 1; k <= endid; k++ ){cout<<res1[k]<<" ";}
                    //     cout<<endl;
                    for( int k = 1; k <= endid; k++ ){
                        if( res1[k]*2 == res1[endid] ){
                            // cout<<i<<"==="<<j<<endl;
                            num++;
                            break;
                        }
                    }
                }
                endid = res2[0];
                if( endid%2 == 0 ){
                    for( int k = 1; k <= endid; k++ ){
                        if( res2[k]*2 == res2[endid] ){
                            // cout<<j<<"==="<<i<<endl;
                            num++;
                            break;
                        }
                    }
                }
                free(res1);
                free(res2);
            }
            
            
        }
    }
    cout<<num<<endl;

    return;
}


int main() 
{ 
    clock_t c1 = clock();
    freopen(   "E:\\VS_code\\C++\\in.in", "r",  stdin ); //输入重定向，输入数据将从in.txt文件中读取
    freopen( "E:\\VS_code\\C++\\out.out", "w", stdout ); //输出重定向，输出数据将保存在out.txt文件中
    //=======================================================================================
    int T =1;
    // cin >> T;
    while( T-- ){
        solve();
    }
   
    
    return 0; 
    //=======================================================================================
    cerr <<"\n\nTime Used:" << clock() - c1 << "ms" <<endl;
    fclose(stdin);//关闭文件
    fclose(stdout);//关闭文件
}

