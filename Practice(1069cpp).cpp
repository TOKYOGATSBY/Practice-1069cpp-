#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int M;
    cin >> M;

    vector<int> prufer(M);
    for (int i = 0; i < M; i++) {
        cin >> prufer[i];
    }
    
    int N = M + 1;

    vector<int> freq(N + 1, 0);
    for (int v : prufer) {
        freq[v]++;
    }

    multiset<int> leaves;
    for (int v = 1; v <= N; v++) {
        if (freq[v] == 0) leaves.insert(v);
    }

    vector<vector<int>> adj(N + 1);

    for (int c : prufer) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());

        adj[leaf].push_back(c);
        adj[c].push_back(leaf);

        freq[c]--;
        if (freq[c] == 0) leaves.insert(c);
    }

    for (int v = 1; v <= N; v++) {
        sort(adj[v].begin(), adj[v].end());
        cout << v << ":";
        if (!adj[v].empty()) cout << " ";
        for (int i = 0; i < (int)adj[v].size(); i++) {
            cout << adj[v][i];
            if (i + 1 < (int)adj[v].size()) cout << " ";
        }
        cout << endl;
    }

    return 0;   
}
