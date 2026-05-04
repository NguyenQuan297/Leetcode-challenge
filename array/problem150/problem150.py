from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack: List[int] = []
        ops = {"+", "-", "*", "/"}

        for token in tokens:
            if token in ops:
                b, a = stack.pop(), stack.pop()
                if token == "+":
                    stack.append(a + b)
                elif token == "-":
                    stack.append(a - b)
                elif token == "*":
                    stack.append(a * b)
                else:
                    stack.append(int(a / b))  # truncate toward zero
            else:
                stack.append(int(token))

        return stack[0]
