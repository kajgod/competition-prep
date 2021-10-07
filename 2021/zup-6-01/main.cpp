#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isTriple(int a, int b, int c) {
    return a > 9 && b > 9 && c > 9;
}

int calcSum(int a, int b, int c) {
    return a + b + c;
}

int calcLack(int a, int b, int c) {
    if(a < 10)return 30 - a - b - c;
    if(b < 10)return 20 - b - c;
    return 10 - c;
}

int main()
{
    int a[5];
    for(int i = 0; i < 5; i++) cin >> a[i];
    int s = sizeof(a) / sizeof(a[0]);
    sort(a, a + s);
    if(isTriple(a[4], a[3], a[2])){
        cout << "DA" << endl;
        cout << calcSum(a[4], a[3], a[2]) << endl;
    } else {
        cout << "NE" << endl;
        cout << calcLack(a[4], a[3], a[2]) << endl;
    }
    return 0;
}
