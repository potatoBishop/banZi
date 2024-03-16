#include<iostream>
#include<cstring>

using namespace std;

void solve(){
	int n;
	cin>>n;
	int a[200];
	int out[200];
	memset(out, 0, sizeof(out));
	for( int i =1; i<= n; i++ ){
		cin >> a[i];
	}
	int num1 = -1, num2 = -1;
	for( int i = 1; i < n; i++ ){
		for( int j = i+1; j <= n; j++){
			if( a[i] == a[j] ){
				if( num1 == -1 ){
					num1 = a[i];
				} else if( num2 == -1 && a[i] != num1 ){
					num2 = a[i];
				}
				if( a[i] == num1 ) out[j] = 2;
				if( a[i] == num2 ) out[j] = 3;		
			}
		}
		if( num1 != -1&& num2 != -1 ) break;
	}
	if( num1 != -1&& num2 != -1 ){
		for( int i = 1; i <= n; i++ ){
			if( out[i] == 0 ) cout<<1<<" ";
			else cout<<out[i]<<" ";
		}
	} else {
		cout<<-1;
	}
	cout<<endl;
}

int main(  ){
	int T;
	cin >> T;
	while( T-- )
	{
		solve();
	}	

}

