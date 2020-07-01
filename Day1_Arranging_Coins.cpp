class Solution {
public:
    //Formula of Sum of first N natural numbers can be used to get the answer (One of the quadratic roots)
    int arrangeCoins(int n) {
        //Equation is of fixed form: (answer^2)+(answer)-(2*n)=0
        int answer=(-1+(sqrt(1+((long long int)4*2*n))))/2;
        return answer;
    }
};
