#include <bits/stdc++.h>

using namespace std;

long long ways[25][6*24 + 1];
long long po6[25];

void generate_ways() {
    for (int n = 0; n <= 24; n++) {
        for (int l = 0; l <= 6*24 + 1; l++) {
            if (n == 0) {
                ways[n][l] = 0;
            } else if (l < n) {
                ways[n][l] = 0;
            } else if (l == n) {
                ways[n][l] = 1;
            }
        }
    }
    for (int l = 1; l <= 6*24 + 1; l++) {
        if (l <= 6)
            ways[1][l] = 1;
        else
            ways[1][l] = 0;
    }
    for (int n = 2; n <= 24; n++) {
        for (int l = n + 1; l < 24*6 + 1; l++) {
            int min = (l - 6 > 0)? l-6 : 0;
            ways[n][l] = 0;
            for (int k = min; k <= l - 1; k++) {
                ways[n][l] += ways[n-1][k];
            }
        }
    }
    for (int i = 0; i <= 24; i++) {
        po6[i] = pow(6,i);
    }
    ways[0][0] = 1;
}

int count(long long i) {
    int c = 0;
    while ( i > 0) {
        if (i % 2 == 1)
            c++;
        i = i/2;
    }
    return c;
}

int get_bit(long long i, int bit_place) {
    return (i >> bit_place) & 1;
}

int main() {
    generate_ways();
    int K, T;
    cin >> K >> T;
    int rolls[K], min_count = 25;
    double max = 0.0;
    int sum = 0;
    for (int i = 0; i < K; i ++) {
        cin >> rolls[i];
        sum += rolls[i];
    }
    //cout << sum << "\n";
    for (long long i = 0; i < (1 << K); i++) {
        int cur_sum = 0, c = count(i);
        for (int j = 0; j < K; j++) {
            if (get_bit(i, j) == 1)
              cur_sum += rolls[j];
        }
        if (sum - cur_sum > T)
          continue;
        double way = (ways[c][T - (sum - cur_sum)])/pow(6,c);
        //cout << cur_sum << "\n";
        // cout << "Testing " << i << " to sum: " << T - (sum - cur_sum) << "Count: " << c << " ways " << way << "\n";
        if (way > max) {
            max = way;
            min_count = c;
        } else if (way == max && c < min_count)
            min_count = c;
    }
    cout << min_count <<"\n";
}
