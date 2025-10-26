def reverse_string(s):
    stack = []
    for char in s:
        stack.append(char)

    reversed_str = ""
    while stack:
        reversed_str += stack.pop()
    return reversed_str


# Driver Code
string = input("Enter a string: ")
print("Reversed String:", reverse_string(string))
