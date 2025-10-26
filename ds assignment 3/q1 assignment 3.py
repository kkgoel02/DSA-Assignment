class Stack:
    def __init__(self, size):
        self.stack = [None] * size
        self.top = -1
        self.size = size

    def isEmpty(self):
        return self.top == -1

    def isFull(self):
        return self.top == self.size - 1

    def push(self, value):
        if self.isFull():
            print("Stack Overflow!")
        else:
            self.top += 1
            self.stack[self.top] = value
            print(f"Pushed {value}")

    def pop(self):
        if self.isEmpty():
            print("Stack Underflow!")
        else:
            popped = self.stack[self.top]
            self.top -= 1
            print(f"Popped {popped}")

    def peek(self):
        if self.isEmpty():
            print("Stack is Empty!")
        else:
            print(f"Top Element: {self.stack[self.top]}")

    def display(self):
        if self.isEmpty():
            print("Stack is Empty!")
        else:
            print("Stack elements:", self.stack[:self.top+1])

# Driver Code
if __name__ == "__main__":
    size = int(input("Enter stack size: "))
    s = Stack(size)

    while True:
        print("\nMenu: 1.Push  2.Pop  3.Peek  4.Display  5.Exit")
        choice = int(input("Enter your choice: "))

        if choice == 1:
            val = input("Enter value to push: ")
            s.push(val)
        elif choice == 2:
            s.pop()
        elif choice == 3:
            s.peek()
        elif choice == 4:
            s.display()
        elif choice == 5:
            break
        else:
            print("Invalid choice!")
