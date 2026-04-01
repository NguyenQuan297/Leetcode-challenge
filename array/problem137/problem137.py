from typing import List


class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        # Bitmask DP: ones holds bits seen 1 mod 3, twos holds bits seen 2 mod 3
        ones = 0
        twos = 0
        for x in nums:
            ones = (ones ^ x) & ~twos
            twos = (twos ^ x) & ~ones

        # Convert to signed 32-bit integer (Python ints are unbounded)
        ones &= 0xFFFFFFFF
        if ones & (1 << 31):
            ones -= 1 << 32
        return ones
