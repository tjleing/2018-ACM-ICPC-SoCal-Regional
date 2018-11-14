#include <bits/stdc++.h>

using namespace std;

int component[100][100];
int degree[100][100];
bool is_component[100];
void merge(int from, int to) {
    is_component[from] = false;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (component[i][j] == from)
                component[i][j] = to;
        }
    }
}
bool is_poly(int num) {
    if (num <= 0)
        return false;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (component[i][j] == num && degree[i][j]!=2)
                return false;
        }
    }
    return true;
}
int main() {
    int x1, y1, x2, y2, component_num = 0, figures = 0;
    for (int i = 0; i < 100; i++) {
        is_component[i] = false;
        for (int j = 0; j < 100; j++) {
            component[i][j] = -1;
            degree[i][j] = 0;
        }
    }
    char c;
    while (cin >> c >> x1 >> c >> y1 >> c >> c >> c >> x2 >> c >> y2 >> c >> c) {
        int c1 = component[x1][y1], c2 = component[x2][y2];
        degree[x1][y1]++;
        degree[x2][y2]++;
        // printf("(%d, %d), (%d, %d), %d, %d\n", x1,y1,x2,y2,c1,c2);
        if (c1 == -1 && c2 == -1) {
            component_num++;
            component[x1][y1] = component_num;
            component[x2][y2] = component_num;
            is_component[component_num] = true;
            figures++;
        } else if (c1 == -1 && c2 > 0) {
            component[x1][y1] = c2;
        } else if (c1 > 0 && c2 == -1) {
            component[x2][y2] = c1;
        } else if (c1 > 0 && c2 > 0 && c1 != c2) {
            merge(c1, c2);
            figures--;
        }
    }
    int poly = 0;
    for (int i = 1; i <= component_num; i++) {
        if (is_component[i] && is_poly(i))
            poly++;
    }
    cout << figures << ' ' << poly << "\n";
}
