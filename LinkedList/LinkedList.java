package LinkedList;

import java.util.NoSuchElementException;

public class LinkedList {
	private class Node {
		private int value;
		private Node next;
		
		public Node(int value) {
			this.value = value;
		}
	}
	
	private Node first;
	private Node last;
	private int size;
	
	private boolean isEmpty() {
		return first == null;
	}
	
	private Node getPrevious(Node node) {
		var current = first;
		while (current.next != null) {
			if (current.next == node)
				break;
			current = current.next;
		}
		return current;
	}
	
	public void addFirst(int item) {
		var node = new Node(item);
		
		if (isEmpty()) 
			first = last = node;
		else {
			node.next = first;
			first = node;
		}
		size++;
	}
	
	public void addLast(int item) {
		var node = new Node(item);
		
		// If the LinkedList is empty
		if (isEmpty()) 
			first = last = node;
		else {
			last.next = node;
			last = node;
		}		
		size++;
	}
	
	public void removeFirst() {
		if (isEmpty()) 
			throw new NoSuchElementException();
		
		if (first == last) { // If we have only one element.
			first = last = null;
			return;
		}
		
		var second = first.next;
		first.next = null; // To make garbage collectable. // Break the Link
		first = second;
		
		size--;
	}
	
	public void removeLast() {
		if (isEmpty()) 
			throw new NoSuchElementException();
		
		if (first == last) { // If we have only one element.
			first = last = null;
			return;
		}
		
		var secondToLast = getPrevious(last);
 		secondToLast.next = null;
 		last = secondToLast;
 		
 		size --;
	}
	
	public int indexOf(int item) {
		int index = 0;
		var node = first;
		while (node != null) {
			if (node.value == item) {
				return index;
			}
			node = node.next;
			index += 1;
		}
		
		return -1;
	}
	
	public boolean contains(int item) {
		return indexOf(item) != -1;
	}
	
	public int size() {
		return size;
	}
	
	public int[] toArray() {
		int[] myArr = new int[size];
		var current = first;
		int index = 0;
		
		while (current != null) {
			myArr[index++] = current.value;
			current = current.next;
		}
		
		return myArr;
	}
	
	public void reverse() {
		// Using the Two-Pointer Approach and Substitute. 
		if (isEmpty()) return;
		
		Node previous = null;
		Node current = first;
		Node next;
		
		while (current != null) {
			next = current.next;
			current.next = previous;
			previous = current;
			current = next;
		}
		
		last = first;
		first = previous; // Current is null.
	}
	
	public int findKthNode(int k) {
		var left = first;
		var right = first;
		
		for (int i = 0; i < k; i++) {
			right = right.next;
		}
		
		while (right != null) {
			left = left.next;
			right = right.next;
		}
		
		return left.value;
	}
	
	public void sort() {
		// Bubble Sort
		if (isEmpty()) return;
		
		var previous = first;
		var current = first.next;
		Node node;
		
		while (current.next != null) {
			if (previous.value > current.value) { // Swap takes place
				node = current.next;
				current.next = previous;
				previous = node;
			}
		}
		// TODO assign the first(head) node.
	}
	
}
