#include<stdio.h>
#include<iostream>


using namespace std;

int main() {
	int n, sd;
	cin >> n >> sd;
	int* a = new int[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	int tmp = a[0];
	for (int i = 0; i < n-(sd % n); i++) {
		for (int j = n-1; j > 0; j--) {
			tmp = a[j];
			a[j] = a[j - 1];
			a[j - 1] = tmp;
		}
	}
	for (int i = 0; i < n; ++i) cout << a[i] << " ";
	delete[] a;
	return 0;
}