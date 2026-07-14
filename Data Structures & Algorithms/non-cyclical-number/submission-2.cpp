class Solution {
public: 
    int sumOfDigitSquares(int n) { 
        int sum=0; 
        while(n) { 
            int digit=n%10; 
            sum+=digit*digit; 
            n/=10; 
        } 
        return sum; 
    }
    bool isHappy(int n) { 
        int slow=n,fast=sumOfDigitSquares(n); 
        while(slow!=fast) { 
            fast=sumOfDigitSquares(fast); 
            fast=sumOfDigitSquares(fast); 
            slow=sumOfDigitSquares(slow); 
        }
        return fast==1; 
    }
};
