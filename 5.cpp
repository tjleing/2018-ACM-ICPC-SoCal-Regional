#include <bits/stdc++.h>

using namespace std;

double PI = 3.1415926535897932384;
pair<double, double> rotate(double x, double y, double theta) {
    double x1 = x*cos(theta) - y*sin(theta);
    double y1 = x*sin(theta) + y*cos(theta);
    return make_pair(x1, y1);
}

int main() {
    int N;
    cin >> N;
    vector<pair<double, double>> v(N), altered(N);
    for(int i = 0; i < N; i++) {
        double x,y;
        cin >> x >> y;
        v[i] = make_pair(x,y);
    }
    double min = 5050000;
    for (int i = 0; i < 10000000; i++) {
        double theta = i * PI/10000000;
        for (int j = 0; j < N; j++) {
            altered[j] = rotate(v[j].first, v[j].second, theta);
        }
        std::sort(altered.begin(), altered.end());
        if (altered[N-1].first - altered[0].first < min)
            min =altered[N-1].first - altered[0].first;
    }
    printf("%2f\n", min);
}
