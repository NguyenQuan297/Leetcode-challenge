from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        # Add one from the least significant digit, propagating carry as needed
        for i in range(len(digits) - 1, -1, -1):
            if digits[i] < 9:
                digits[i] += 1
                return digits
            digits[i] = 0
        # If all digits were 9, prepend leading 1
        return [1] + digits
