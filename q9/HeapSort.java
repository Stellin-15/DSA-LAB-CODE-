import java.util.*;

public class HeapSort {
  
    public void sort(String arr[]) {
      int n = arr.length;
  
      // Build max heap
      for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
      }
  
      // Heap sort
      for (int i = n - 1; i >= 0; i--) {
        String temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
  
        // Heapify root element
        heapify(arr, i, 0);
      }
    }
  
    void heapify(String arr[], int n, int i) {
      // Find largest among root, left child and right child
      printArray1(arr); 
      int largest = i;
      int l = 2 * i + 1;
      int r = 2 * i + 2;
  
      if (l < n && arr[l].compareTo(arr[largest]) > 0)
        largest = l;
  
      if (r < n && arr[r].compareTo(arr[largest]) > 0)
        largest = r;
  
      // Swap and continue heapifying if root is not largest
      if (largest != i) {
        String swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;
        
        
        heapify(arr, n, largest);
      }
    }
  
    // Function to print an array
    static void printArray1(String arr[]) {
      int n = arr.length;
      System.out.print("STEPS: ");
      for (int i = 0; i < n; ++i)
        System.out.print(arr[i] + " | ");
      System.out.println();
    }
    static void printArray(String arr[]) {
      int n = arr.length;
      
      for (int i = 0; i < n; ++i)
        System.out.print(arr[i] + " | ");
      System.out.println();
    }
  
    // Driver code
    public static void main(String args[]) {
      String arr[] = { "#$BiT", "Raj1", "Boy2", "1Kind", "&zebra", "Gate2", "joKe1", "poKer3", "tRicK4", "3Dial",
        "1RoaD", "QueeN7" };
  
      HeapSort hs = new HeapSort();
      hs.sort(arr);
  
      System.out.println("Sorted array is");
      printArray(arr);
    }
  }