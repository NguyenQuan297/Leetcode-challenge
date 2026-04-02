class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        # XOR all chars: duplicates from s cancel; extra char in t remains
        x = 0
        for c in s:
            x ^= ord(c)
        for c in t:
            x ^= ord(c)
        return chr(x)
