#include <bits/stdc++.h>
using namespace std;

#define NMAX 100005
#define INF (1LL << 60)

struct DijkstraResult {
    vector<long long> d;
    vector<int> p;

    DijkstraResult(const vector<long long>& d, const vector<int>& p)
        : d(d)
        , p(p) { }
};

class Task {
 public:
    void solve() {
        read_input();
        get_result();
        print_output();
    }

 private:
    int n, m, x, y, z;
    vector<pair<int, long long>> adj[NMAX];
    long long min_dist;

    void read_input() {
        ifstream fin("drumuri.in");
        long long c;
        fin >> n >> m;
        for (int i = 0, a, b; i < m; i++) {
            fin >> a >> b >> c;
            adj[a].push_back({b, c});
        }
        fin >> x >> y >> z;
        fin.close();
    }

    void get_result() {
        auto x_way = dijkstra(x, n);
        auto y_way = dijkstra(y, n);

        long long x_to_z = x_way.d[z];
        long long y_to_z = y_way.d[z];

        // check if i can reach the required destinations
        if (x_to_z == -1 || y_to_z == -1) {
            min_dist = -1;
        } else {
            min_dist = x_to_z + y_to_z;
        }
    }

    DijkstraResult dijkstra(int source, int nodes) {
        vector<long long> d(nodes + 1, INF);
        vector<int> p(nodes + 1, -1);

        set<pair<long long, int>> pq;

        d[source] = 0;
        pq.insert({d[source], source});

        while (!pq.empty()) {
            auto top = pq.begin();
            int node = top->second;
            pq.erase(top);

            for (auto [neigh, w] : adj[node]) {
                if (d[node] + w < d[neigh]) {
                    // if the node is already in the set, erase it
                    if (pq.find({d[neigh], neigh}) != pq.end()) {
                         pq.erase({d[neigh], neigh});
                    }
                    d[neigh] = d[node] + w;
                    p[neigh] = node;
                    pq.insert({d[neigh], neigh});
                }
            }
        }

        // set the nodes that can't be reached to -1
        for (int node = 1; node <= nodes; node++) {
            if (d[node] == INF) {
                d[node] = -1;
            }
        }

        return DijkstraResult(d, p);
    }

    void print_output() {
        ofstream fout("drumuri.out");
        fout << min_dist << "\n";
        fout.close();
    }
};

int main() {
    auto* task = new (nothrow) Task();
    if (!task) {
        cerr << "Memory allocation failed.\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
