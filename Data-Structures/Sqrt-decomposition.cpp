class sqrt_dec_max_min {
    int len, n;
    vector<int> blc_min, blc_max, arr;

public:
    sqrt_dec_max_min(int a[], int n) {
        len = int(sqrt(n) + 1);
        blc_min = vector<int>(len, INF);
      	blc_max = vector<int>(len, 0);
        arr.assign(a, a + n);
        this->n = n;
    }
    
    void pre_max() {
        for (int i = 0; i < n; i++) {
            int j = i / len;
            blc_max[j] = max(blc_max[j], arr[i]);
        }
    }

    void pre_min() {
        for (int i = 0; i < n; i++) {
            int j = i / len;
            blc_min[j] = min(blc_min[j], arr[i]);
        }
    }
 
    int get_max(int l, int r) {
        int mx = 0, c_l = l / len, c_r = r / len, end = (c_l + 1) * len - 1;
        if (c_l == c_r) {
            for (int i = l; i <= r; i++)
                mx = max(mx, arr[i]);
        } else {
            for (int i = l; i <= end; i++)
                mx = max(mx, arr[i]);
            for (int i = c_l + 1; i <= c_r - 1; i++)
                mx = max(mx, blc_max[i]);
            for (int i = c_r * len; i <= r; i++)
                mx = max(mx, arr[i]);
        }
        return mx;
    }

    int get_min(int l, int r) {
        int mn = INF, c_l = l / len, c_r = r / len, end = (c_l + 1) * len - 1;
        if (c_l == c_r) {
            for (int i = l; i <= r; i++)
                mn = min(mn, arr[i]);
        } else {
            for (int i = l; i <= end; i++)
                mn = min(mn, arr[i]);
            for (int i = c_l + 1; i <= c_r - 1; i++)
                mn = min(mn, blc_min[i]);
            for (int i = c_r * len; i <= r; i++)
                mn = min(mn, arr[i]);
        }
        return mn;
    }
};
