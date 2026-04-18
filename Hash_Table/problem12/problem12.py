class Solution:
    def intToRoman(self, num: int) -> str:
        # Lookup tables: decimal digit at each place -> Roman fragment
        thousands: dict[int, str] = {0: "", 1: "M", 2: "MM", 3: "MMM"}
        hundreds: dict[int, str] = {
            0: "",
            1: "C",
            2: "CC",
            3: "CCC",
            4: "CD",
            5: "D",
            6: "DC",
            7: "DCC",
            8: "DCCC",
            9: "CM",
        }
        tens: dict[int, str] = {
            0: "",
            1: "X",
            2: "XX",
            3: "XXX",
            4: "XL",
            5: "L",
            6: "LX",
            7: "LXX",
            8: "LXXX",
            9: "XC",
        }
        ones: dict[int, str] = {
            0: "",
            1: "I",
            2: "II",
            3: "III",
            4: "IV",
            5: "V",
            6: "VI",
            7: "VII",
            8: "VIII",
            9: "IX",
        }
        return (
            thousands[num // 1000]
            + hundreds[(num % 1000) // 100]
            + tens[(num % 100) // 10]
            + ones[num % 10]
        )
