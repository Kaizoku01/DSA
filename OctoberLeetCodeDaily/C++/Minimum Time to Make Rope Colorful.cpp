class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int n = colors.size();
        int i = 0;
        while(i < n) {
            int j = i;
            while(j < n-1 && colors[j] == colors[j+1]) ++j;
            int maxi = INT_MIN;
            for(int k = i; k <= j; k++)
            {
                maxi = max(neededTime[k], maxi);
                ans += neededTime[k];
            }
            ans -= maxi;
            i = j + 1;
        }
        return ans;
    }
};
