const int N = 1e5;

int parent[N], rnk[N], sz[N];
 
void make_set(int v) {
    parent[v] = v;
    rnk[v] = 0;
	sz[v] = 1;	
}
 
int find_set(int v) {
    return parent[v] == v ? v : parent[v] = find_set(parent[v]);
}
 
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        parent[b] = a;
		sz[a] += sz[b];
		sz[b] = 0;
        if (rnk[a] == rnk[b])
            ++rnk[a];
    }
}
