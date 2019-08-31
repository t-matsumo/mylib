#include <bits/stdc++.h>

using ll = long long;
using namespace std;

constexpr static ll MOD = 1000000007ll;
constexpr static int INF = 1 << 28; // for x <= 10^9
constexpr static ll INFL = 1ll << 60; // for x <= 10^19
constexpr static double EPS = 1e-10;

class UnionFind {
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    /**
     * Union find 0 ~ (n - 1)
     */
    UnionFind(int n) {
        this->parent = vector<int>(n);
        this->size = vector<int>(n);
        this->rank = vector<int>(n);

        for (int i = 0; i < n; i++) {
            this->parent[i] = i;
            this->rank[i] = 0;
            this->size[i] = 1;
        }
    }

    int findRoot(int x) {
        if (this->parent[x] == x) {
            return x;
        }

        this->parent[x] = this->findRoot(this->parent[x]);
        return this->parent[x];
    }

    bool sameRoot(int x, int y) { return this->findRoot(x) == this->findRoot(y); }

    void unite(int x, int y) {
        x = this->findRoot(x);
        y = this->findRoot(y);
        if (x == y) {
            return;
        }

        if (rank[x] < rank[y]) {
            this->parent[x] = y;
            this->size[y] += this->size[x];
        } else {
            this->parent[y] = x;
            if (rank[x] == rank[y]) {
                rank[x]++;
            }

            this->size[x] += this->size[y];
        }
    }

    ll getSize(int x) { return this->size[findRoot(x)]; }
};
