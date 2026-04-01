from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        # Two pointers: widest container first, then move the shorter side inward
        left, right = 0, len(height) - 1
        best = 0
        while left < right:
            # Water level is limited by the shorter line; width is index distance
            h = min(height[left], height[right])
            best = max(best, h * (right - left))
            # Discarding the taller side cannot improve area (width shrinks, height capped by shorter)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return best
