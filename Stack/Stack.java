import java.util.Arrays;
import java.util.EmptyStackException;

public class Stack {
    // Methods
    // - Peek, Pop, Push, Empty, Clear, Size, Show
    private int size = 2;
    private int[] stack = new int[size];
    private int pointer = 0;

    public void push(int item) {
        if (pointer < size)
            stack[pointer++] = item;
        else {
            size *= 2;
            stack = Arrays.copyOf(stack, size); // Creates a copy of stack but with more size
        }
              
    }

    public int pop(){
        if (empty())
            throw new EmptyStackException();
        return stack[--pointer];
    }

    public boolean empty() {
        return pointer == 0;
    }

    public int peek() {
        if (empty())
            throw new EmptyStackException();
        return stack[pointer - 1];
    }

    public String show() {
        int[] temp = new int[pointer];
        for (int i = 0; i < pointer; i++) {
            temp[i] = stack[i];
        }

        return Arrays.toString(temp);
    }

    public int size() {
        return pointer;
    }

    public void clear() {
        stack = new int[size];
        pointer = 0;
    }
}