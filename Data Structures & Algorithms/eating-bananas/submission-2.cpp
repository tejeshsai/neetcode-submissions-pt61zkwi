class Solution {
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int low_rate = 1;
        int high_rate = 0;
        int n = piles.size();
        int result = 0;
        for(int i:piles){
            high_rate = max(high_rate, i);
        }

        while(low_rate<high_rate){
            int k = (low_rate+high_rate)/2;
            int total_hours = 0;
            for(int i=0;i<n;i++){
                total_hours+= piles[i]/k + (piles[i]%k!=0);
            }
            if(total_hours>h){
                low_rate = k+1;
            }else{
                high_rate = k;
            }
        }
        return low_rate;

    }
};
