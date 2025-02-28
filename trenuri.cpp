#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Task {
 public:
    void solve() {
        read_input();
        print_output(get_result());
    }

 private:
    string start, end;
    unordered_map<string, vector<string>> graph;
    unordered_map<string, int> dp;

    void read_input() {
        ifstream fin("trenuri.in");
        fin >> start >> end;

        int M;
        fin >> M;

        for (int i = 0; i < M; ++i) {
            string u, v;
            fin >> u >> v;
            graph[u].push_back(v);
        }
        fin.close();
    }

    int get_result() {
        return find_longest(start, end);
    }

    int find_longest(string &start, string &destination) {
        if (start == destination) {
            return 1;
        }

        // return the result
        if (dp.find(start) != dp.end()) {
            return dp[start];
        }

        // search for the path with the greatest length
        int max_length = 0;
        for (auto &neighbor : graph[start]) {
            max_length = max(max_length, find_longest(neighbor, destination));
        }

        // store the results
        dp[start] = 1 + max_length;
        return dp[start];
    }

    void print_output(int result) {
        ofstream fout("trenuri.out");
        fout << result << "\n";
        fout.close();
    }
};

int main() {
    Task *task = new (nothrow) Task();
    if (task == nullptr) {
        cerr << "Memory allocation failed" << endl;
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
