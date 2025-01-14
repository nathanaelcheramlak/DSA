# Application of stack (Infix to Postfix Converter)
def precedence(operator):
    if operator in ['+', '-']:
        return 1
    elif operator in ['*', '/']:
        return 2
    elif operator == '^':
        return 3
    return 0

def is_operator(char):
    return char in ['+', '-', '*', '/', '^']

def calculate_postfix(expression):
    result = 0
    stack = []
    for char in expression:
        if is_operator(char):
            y = stack.pop()
            x = stack.pop()
            if char == '+':
                stack.append(x + y)
            elif char == '-':
                stack.append(x - y)
            elif char == '*':
                stack.append(x * y)
            elif char == '/':
                stack.append(x / y)
            else:
                stack.append(x ** y)
        elif char.isdigit():
            stack.append(int(char))
        else:
            print("Invalid Expression")
            return
    if len(stack) != 1:
        print("Invalid Expression")
        return

    return stack.pop()


def main(expression):
    stack = []
    output = []

    for char in expression:
        if char == ')':
            while stack[-1] != '(':
                output.append(stack.pop())
            stack.pop() # Remove '(' from the stack

        elif char == '(':
            stack.append(char)
        
        elif is_operator(char):
            while stack and precedence(stack[-1]) >= precedence(char):
                output.append(stack.pop())
            stack.append(char)
        else:
            output.append(char)

    # Append the remaining operators
    while stack:
        output.append(stack.pop())

    return ''.join(output)

expression = "2+(4*1-(8/2^2)*3)*5"
postfix = main(expression)
result = calculate_postfix(postfix)

print("Original: ", expression)
print("Postfix: ", postfix)
print("Result: ", result)
