// Java program for implementation of QuickSort
import java.util.*;

class QuickSort {
  /* This function takes last element as pivot, places the pivot element
  at its correct position in sorted array, and places all smaller
  (smaller than pivot) to left of pivot and all greater elements to right
  of pivot */
  static int parition( int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low-1); // index of smaller element

    for( int j=low; j<=high-1; j++) {
      // If current element is smaller than or equal to povot
      if( arr[j] <= pivot) {
        i++;

        // swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    // swap arr[i+1] and arr[high] (or pivot)
    int temp = arr[ i+1];
    arr[ i+1] = arr[ high];
    arr[ high] = temp;

    return i+1;
  }

  /* The main function that implements QuickSort() 
  arr[] --> Array to be sorted,
  low --> Starting index,
  high --> Ending index */
  static void qSort( int arr[], int low, int high) {
    if( low<high) {
      // pi is partitioning index, arr[pi] is now at right place
      int pi = partition( arr, low, high);

      // Recursively sort elements befere partition
      // and right place
      qSort( arr, low, pi-1);
      qSort( arr, pi+1, high);
    }
  }
}
    
