class sqrt_dec {
    int len, n;
    vector<int> blc, a;

public:
    sqrt_dec(int a[], int n) {
        len = int(sqrt(n) + 1);
        blc = vector<int>(len);
        this->a.assign(a, a + n);
        this->n = n;
    }

    void pre_sum() {
        for (int i = 0; i < n; i++)
            blc[i / len] += a[i];
    }

    int get_sum(int l, int r) {
        int c_l = l / len, c_r = r / len, end = (c_l + 1) * len - 1;
        int sum = 0;
        if (c_l == c_r) {
            for (int i = l; i <= r; i++)
                sum += a[i];
        } else {
            for (int i = l; i <= end; i++)
                sum += a[i];
            for (int i = c_l + 1; i <= c_r - 1; i++)
                sum += blc[i];
            for (int i = c_r * len; i <= r; i++)
                sum += a[i];
        }
        return sum;
    }
};


class sqrt_dec_sum_max {
    int len, n;
    vector<int> blc_sum, blc_max, a_sum, a_max;
 
public:
    sqrt_dec(int a[], int b[], int n) {
        len = int(sqrt(n) + 1);
        blc_sum = blc_max = vector<int>(len);
        this->a_sum.assign(a, a + n);
        this->a_max.assign(b, b + n);
        this->n = n;
    }
 
    void pre_sum() {
        for (int i = 0; i < n; i++)
            blc_sum[i / len] += a_sum[i];
    }
 
    void pre_max() {
        for (int i = 0; i < n; i++) {
            int j = i / len;
            blc_max[j] = max(blc_max[j], a_max[i]);
        }
    }
 
    int get_sum(int l, int r) {
        int sum = 0, c_l = l / len, c_r = r / len, end = (c_l + 1) * len - 1;
        if (c_l == c_r) {
            for (int i = l; i <= r; i++)
                sum += a_sum[i];
        } else {
            for (int i = l; i <= end; i++)
                sum += a_sum[i];
            for (int i = c_l + 1; i <= c_r - 1; i++)
                sum += blc_sum[i];
            for (int i = c_r * len; i <= r; i++)
                sum += a_sum[i];
        }
        return sum;
    }
 
    int get_max(int l, int r) {
        int mx = 0, c_l = l / len, c_r = r / len, end = (c_l + 1) * len - 1;
        if (c_l == c_r) {
            for (int i = l; i <= r; i++)
                mx = max(mx, a_max[i]);
        } else {
            for (int i = l; i <= end; i++)
                mx = max(mx, a_max[i]);
            for (int i = c_l + 1; i <= c_r - 1; i++)
                mx = max(mx, blc_max[i]);
            for (int i = c_r * len; i <= r; i++)
                mx = max(mx, a_max[i]);
        }
        return mx;
    }
};
