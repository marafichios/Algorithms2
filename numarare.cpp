#include <fstream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

#define MOD 1000000007

using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    int N, M;
    vector<unordered_map<int, int>> edges;
    vector<vector<int>> intersection;
    vector<int> nodes_in;

    void read_input() {
        ifstream fin("numarare.in");
        fin >> N >> M;

        edges.resize(N + 1);
        intersection.resize(N + 1);
        nodes_in.resize(N + 1, 0);

        int x, y;
        for (int i = 0; i < M; ++i) {
            fin >> x >> y;
            edges[x][y] = 1;
        }

        for (int i = 0; i < M; ++i) {
            fin >> x >> y;
            if (edges[x][y] == 1) {
                // if the edge is in both graphs, add it to the intersection
                intersection[x].push_back(y);
                nodes_in[y]++;
            }
        }
        fin.close();
    }

    int get_result() {
        vector<long long> dp(N + 1, 0);
        dp[1] = 1;

        queue<int> q;
        for (int i = 1; i <= N; i++) {
            if (nodes_in[i] == 0) {
                q.push(i);
            }
        }

        // topological sort from the lab
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int v : intersection[node]) {
                dp[v] = (dp[v] + dp[node]) % MOD;
                nodes_in[v]--;
                if (nodes_in[v] == 0) {
                    q.push(v);
                }
            }
        }

        return dp[N];
    }

    void print_output(int result) {
        ofstream fout("numarare.out");
        fout << result << '\n';
        fout.close();
    }
};

int main() {
    auto* task = new (nothrow) Task();
    if (!task) {
        cerr << "Memory allocation failed" << endl;
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
