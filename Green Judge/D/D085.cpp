#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	long long int max = -214748364, min = 2147483647;
	long double sum = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		if (a[i] > max){
			max = a[i];
		}
		if(a[i] < min){
			min = a[i];
		}
	}
	
	cout << fixed << setprecision(2) << sum / n << endl << max << endl << min << endl; 
}

