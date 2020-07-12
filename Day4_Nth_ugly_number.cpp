class Solution {
    //Observation: The ugly number sequence can be formed with previous numbers in sequence multiplied by 2,3,5.
    //Time Complexity: O(N)
    //Space Complexity: O(N)
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0]=1; // First ugly number is 1
        int next_2=2,next_3=3,next_5=5,index2=0,index3=0,index5=0; // Starting from multiplying 1 with 2,3,5
        // index2 points to the number with which 2 needs to be multiplied next
        
        for(int count=1;count<n;count++){
            int next_ugly=min(next_2,min(next_3,next_5));
            dp[count]=next_ugly;
            if(next_ugly==next_2){ // Next ugly number in series is from multiple of 2. Hence 2 is to be multiplied with next number in series.
                index2++;
                next_2=2*dp[index2];
            }
            if(next_ugly==next_3){ 
                index3++;
                next_3=3*dp[index3];
            }
            if(next_ugly==next_5)
            {
                index5++;
                next_5=5*dp[index5];
            }
        }
        
        return dp[n-1];
    }
};
