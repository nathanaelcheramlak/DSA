public class TestRunner {
    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(10);
        stack.push(20);
        stack.clear();
        stack.push(30);
        stack.push(40);
        stack.push(50);
        int last = stack.pop();
        System.out.println("poped element: " + last);
        System.out.println(stack.show());
        System.out.println("size: " + stack.size());
        System.out.println(stack.peek());
        System.out.println("empty? " + stack.empty());
    }
}
