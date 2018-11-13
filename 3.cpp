#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x;
    int y;
};

int N;
vector<Point> pts;
bool graph[1000][1000];

void build_graph(int dist) {
    // True = distance > allowed
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int curr_dist = abs(pts[i].x - pts[j].x) + abs(pts[i].y - pts[j].y);
            if (curr_dist > dist) {
                graph[i][j] = true;
            } else {
                graph[i][j] = false;
            }
        }
    }
}

bool is_two_colorable() {
    int colors[1000];
    bool visited[1000];
    for (int i = 0; i < 1000; i++) {
        colors[i] = -1;
        visited[i] = false;
    }

    queue<int> q;
    q.push(0);
    colors[0] = 0;
    while (!q.empty()) {
        int top = q.front();
        q.pop();
        visited[top] = true;
        int next_color = 1 - colors[top];
        for (int other = 0; other < N; other++) {
            if (graph[top][other] && colors[other] != -1 && colors[other] == colors[top]) {
                return false;
            }
            if (graph[top][other] && !visited[other]) {
                colors[other] = next_color;
                q.push(other);
            }
        }
        if (q.empty()) {
            for (int i = 0; i < N; i++) {
                if (!visited[i]) {
                    q.push(i);
                    break;
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        Point p;
        cin >> p.x >> p.y;
        pts.push_back(p);
    }

    int low = 0;
    int high = 2 * 1000;

    while (low != high) {
        int mid = (low + high) / 2;
        build_graph(mid);
        if (is_two_colorable()) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
}
