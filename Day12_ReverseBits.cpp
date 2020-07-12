class Solution {
public:
	//Approach: If bit at position 0 is set, bit at position 31 should be set when reversed. 1->30, 2->29 and so on...
	//Time complexity: O(1) as input is a fixed 32-bit unsigned int
	//Space Complexity: O(1)
    uint32_t reverseBits(uint32_t n) {
        uint32_t revn=0,pos=31;
        while(n){
            revn+=(n&1)<<pos;
            n>>=1;
            pos--;
        }
        return revn;
    }
};
