class Solution:
    # Single ordered table: greedy subtract largest fitting block (includes subtractive pairs).
    _VALS = (1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1)
    _SYMS = ("M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I")

    def intToRoman(self, num: int) -> str:
        out: list[str] = []
        for v, s in zip(self._VALS, self._SYMS):
            while num >= v:
                out.append(s)
                num -= v
        return "".join(out)
