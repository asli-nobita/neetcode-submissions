class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        #common prefix of left and right 
        #clear rightmost bit of right until left>=right 
        while left<right: 
            right=right&(right-1) 
        return right
