#include <iostream>
using namespace std;
int main() {
    int n, l, w, h;
    double left = 0, right = 1000000000, mid;
    cin >> n >> l >> w >> h;
    for (int i = 0; i < 10000; i++) {
        mid = (left + right) / 2;
        if ((long long)(l / mid) * (long long)(w / mid) * (long long)(h / mid) < n) right = mid;
        else left = mid;
    }
    printf("%.10lf", left);
}