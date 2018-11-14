#include <bits/stdc++.h>

using namespace std;

vector<bool> is_prime(2000010);
vector<int> primes;

void sieve() {
    for(int i = 0; i<2000010; ++i) {
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    for(int i = 2; i<2000010; ++i) {
        if(!is_prime[i]) continue;
        for(int j = 2; i*j<2000010; ++j) {
            is_prime[i*j] = false;
        }
        primes.push_back(i);
    }
}

vector<int> factor(long long a) {
    vector<int> factors;
    for(int i = 0; i<primes.size(); ++i) {
        if(a % primes[i] == 0) {
            while(a % primes[i] == 0) {
                a /= primes[i];
            }
            factors.push_back(primes[i]);
        }
    }
    return factors;
}

int main() {
    sieve();

    long long a, b;
    while(cin >> a >> b) {
        vector<int> afactors = factor(a);
        vector<int> bfactors = factor(b);

        bool isbad = false;
        for(int i = 0; i<afactors.size(); ++i) {
            for(int j = 0; j<bfactors.size(); ++j) {
                if(afactors[i] == bfactors[j]) {
                    isbad = true;
                }
            }
        }
        if(isbad) {
            cout << "bad" << endl;
            continue;
        }
        long long c = a + b;
        vector<int> cfactors = factor(c);
        long long rad = 1;
        for(int i = 0; i<afactors.size(); ++i) {
            rad *= (long long)afactors[i];
        }
        for(int i = 0; i<bfactors.size(); ++i) {
            rad *= (long long)bfactors[i];
        }
        for(int i = 0; i<cfactors.size(); ++i) {
            rad *= (long long)cfactors[i];
        }
        if(rad == c) {
            cout << "equal" << endl;
        }
        else if(rad < c) {
            cout << "less" << endl;
        }
        else {
            cout << "greater" << endl;
        }
    }
}
