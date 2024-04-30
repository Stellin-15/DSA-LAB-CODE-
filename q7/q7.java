
import java.util.*;

class stack_using_singlyLinkedList {

    class node {

        int data;
        node next;

    }

    node top;

    stack_using_singlyLinkedList() {
        this.top = null;
    }

    public void push(int info) {
        node temp = new node();
        if (top == null) {
            System.out.println("stack overflow");
            return;
        }

        temp.data = info;
        temp.next = top;
        top = temp;

    }

    public boolean isEmpty() {
        return top == null;
    }

    // Utility function to return top element in a stack
    public int peek() {
        // check for empty stack
        if (!isEmpty()) {
            return top.data;
        } else {
            System.out.println("Stack is empty");
            return -1;
        }
    }

    public void pop() {
        if (top == null) {
            System.out.println("underflow condition");
            return;
        }
        top = (top).next;
    }

    public void display() {
        // check for stack underflow
        if (top == null) {
            System.out.printf("\nStack Underflow");
            return;
        } else {
            node temp = top;
            while (temp != null) {

                // print node data
                System.out.print(temp.data);

                // assign temp link to temp
                temp = temp.next;
                if (temp != null)
                    System.out.print(" -> ");
            }
        }
    }
}

public class q7{
public static void main(String[] args) {
    // create Object of Implementing class
    stack_using_singlyLinkedList obj = new stack_using_singlyLinkedList();
    // insert Stack value
    obj.push(11);
    obj.push(22);
    obj.push(33);
    obj.push(44);

    // print Stack elements
    obj.display();

    // print Top element of Stack
    System.out.printf("\nTop element is %d\n",
            obj.peek());

    // Delete top element of Stack
    obj.pop();
    obj.pop();

    // print Stack elements
    obj.display();

    // print Top element of Stack
    System.out.printf("\nTop element is %d\n",
            obj.peek());
}
}