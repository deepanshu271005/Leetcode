class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        sort(triplets.begin(), triplets.end());
        int ta = target[0], tb = target[1], tc = target[2];
        int ca = 0, cb = 0, cc = 0;
        //  bool ga=false,gb=false,gc=false;
        for (auto i : triplets) {
            int a = i[0];
            int b = i[1];
            int c = i[2];
            cout << ca << cb << cc <<" "<<ta<<tb<<tc<<endl;
            if (ca == ta && cb == tb && cc == tc)
                return true;

            if (a == ta && b <= tb && c <= tc) {
                ca = ta;
                cb = max(b, cb);
                cc = max(c, cc);
            } else if (b == tb && a <= ta && c <= tc) {
                cb = tb;
                ca = max(a, ca);
                cc = max(c, cc);
            } else if (c == tc && a <= ta && b <= tb) {
                cc = tc;
                ca = max(a, ca);
                cb = max(b, cb);
            }
        }
        cout << ca << cb << cc <<" "<<ta<<tb<<tc;
        if (ca == ta && cb == tb && cc == tc)
            return true;

        return false;
    }
};