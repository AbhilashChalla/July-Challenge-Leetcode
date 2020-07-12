class Solution {
public:
	//Taking XOR of X and Y sets the bits which are different. Counting number of set bits from previous step would give the answer.
	//Time Complexity: O(1)
	//Space Complexity: O(1)
	
    int calculateSetBits(int num){
        int count=0;
        for(int i=0;i<32;i++){
            if(num&(1<<i))
                count++;
        }
        return count;
    }
    int hammingDistance(int x, int y) {
        int xorr=x^y;
        return calculateSetBits(xorr);
    }
};
