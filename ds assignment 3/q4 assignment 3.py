def precedence(op):
    if op in ('+', '-'):
        return 1
    if op in ('*', '/'):
        return 2
    if op == '^':
        return 3
    return 0

def infix_to_postfix(expression):
    stack = []
    result = ""

    for char in expression:
        if char.isalnum():  # Operand
            result += char
        elif char == '(':
            stack.append(char)
        elif char == ')':
            while stack and stack[-1] != '(':
                result += stack.pop()
            stack.pop()
        else:  # Operator
            while stack and precedence(stack[-1]) >= precedence(char):
                result += stack.pop()
            stack.append(char)

    while stack:
        result += stack.pop()

    return result


# Driver Code
expr = input("Enter infix expression: ")
print("Postfix Expression:", infix_to_postfix(expr))
