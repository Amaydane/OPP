#include <iostream>

using namespace std;

template <typename Num>
void swap(Num** a, Num n) {
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tmp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = tmp;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int** a = new int*[n];
    for (int i = 0; i < n; ++i) {
        a[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }
    cout << "\n";
    swap(a, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << " ";
        cout << "\n";
    }
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

