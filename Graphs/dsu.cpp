class UnionFind {
public:
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == root[x]) {
            return x;
        }
        return root[x] = find(root[x]);
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int largestComponentSize(int n) {
        unordered_map<int, int> group;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int rootI = find(i);
            group[rootI]++;
            ans = max(ans, group[rootI]);
        }
        return ans;
    }

    int numberOfConnectedComponents(int n) {
        unordered_set<int> group;
        for (int i = 0; i < n; i++) {
            group.insert(find(i));
        }
        return group.size();
    }

private:
    vector<int> root;
    vector<int> rank;
};


