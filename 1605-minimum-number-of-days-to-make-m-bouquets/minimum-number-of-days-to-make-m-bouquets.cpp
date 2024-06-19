class Solution {
public:
    bool isGood(vector<int>& bloomDay, int m, int k, int mid)
    {
        int res = 0, sum = 0;
        for(int i = 0; i < bloomDay.size(); i++)
        {
            if(bloomDay[i] <= mid) res++;
            else res = 0;
            if(res == k)
            {
                res = 0;
                sum++;
            }
        }
        return sum >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = 1, r = 1e9;
        while(r > l + 1)
        {
            int mid = (l + r)/2;
            if(isGood(bloomDay, m, k, mid)) r = mid;
            else l = mid;
        }
        if(isGood(bloomDay, m, k, l)) return l;
        else if(isGood(bloomDay, m, k, r)) return r;
        else return -1;
    }
};