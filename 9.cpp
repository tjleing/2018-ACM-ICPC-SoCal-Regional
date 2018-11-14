// DO NOT USE THIS, IT HAS A BUG (see README and use 9.py3)
#include <bits/stdc++.h>

using namespace std;

double probability[1000];

int main() {
    for(int i = 0; i<1000; ++i) {
        probability[i] = 1;
    }

    string c;
    while(cin >> c) {
        if(c.length() != 1) break;
        double temp; cin >> temp;
        probability[c[0]] = temp;
    }
    string s = c;
    do {
        double p = 1;
        for(int i = 0; i<s.length(); ++i) {
            if (probability[s[i]] != 1) {
                
                p *= probability[s[i]];
            }

        }
        printf("%.3f\n", p);
    } while(cin >> s);
}
