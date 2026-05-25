class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = INT_MIN;
        for(auto& p : piles){
            r = max(r, p);
        }
        //FIRST TRUE
        while(l<r){
            int k = l+(r-l)/2;
            int sum = 0;
            for(auto& p:piles){
                sum+= (p+k-1)/k;
            }
            if(sum<=h){
                r = k;
            }else{
                l=k+1;
            }
        }
        return l;
    }
};
