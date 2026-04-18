def _roman_value_table():
    t = [0] * 128
    for ch, val in zip("IVXLCDM", (1, 5, 10, 50, 100, 500, 1000)):
        t[ord(ch)] = val
    return tuple(t)


# Built once at import: tuple lookup + no per-call list allocation
_ROMAN = _roman_value_table()


class Solution:
    def romanToInt(self, s: str) -> int:
        T = _ROMAN
        b = s.encode("ascii")
        total = 0
        prev = 0
        i = len(b)
        while i:
            i -= 1
            cur = T[b[i]]
            if cur < prev:
                total -= cur
            else:
                total += cur
            prev = cur
        return total
