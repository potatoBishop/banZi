#include<iostream>
#include<cstring>
using namespace std;

void solve(){
	int n;
	// int a[25] = {0};
	string str;
	cin >> n;
	cin >> str;
	str = " " + str;
	int k1 = 0, k2 = 0;
	for( int i = 1; i <= n; i++ ){
		if( str[i] == 'A' ) k1++;
		else k2++;
	}


	if( n % 2 == 0 && k1 == k2 ) cout<<"?"<<endl;
	else if( str[n] == 'A' ) cout<<"A"<<endl;
	else cout<<"B"<<endl;
}

int main(){
	int T;
	cin >> T;
	while( T -- ){
		solve();
	}


	return 0;
}




