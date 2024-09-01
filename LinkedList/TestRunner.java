package LinkedList;

import java.util.Arrays;

public class TestRunner {
	public static void main(String[] args) {
		LinkedList list = new LinkedList();
		list.addFirst(20);
		list.addFirst(10);
		list.addLast(30);
		list.addLast(40);
		list.addLast(50);
		
//		list.reverse();
		System.out.println(Arrays.toString(list.toArray()));
		System.out.println(list.findKthNode(3));
	}
	
}
