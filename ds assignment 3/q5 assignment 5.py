def evaluate_postfix(expression):
    stack = []

    for char in expression:
        if char.isdigit():
            stack.append(int(char))
        else:
            b = stack.pop()
            a = stack.pop()
            if char == '+':
                stack.append(a + b)
            elif char == '-':
                stack.append(a - b)
            elif char == '*':
                stack.append(a * b)
            elif char == '/':
                stack.append(a // b)  # Integer division

    return stack.pop()


# Driver Code
expr = input("Enter postfix expression (single digit numbers): ")
print("Evaluation Result:", evaluate_postfix(expr))
