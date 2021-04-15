// Quick sort in Java

public class Main {
  public Main(){}

  // divide the array on the basis of pivot
  public int partition(int[] array, int low, int high) {

    // select last element as pivot
    int pivot = array[high];

    // initialize the second pointer
    int i = (low - 1);

    // Put the elements smaller than pivot on the left and
    // greater than pivot on the right of pivot
    for (int j = low; j < high; j = j+1) {

      // compare all elements with pivot
      // swap the element greater than pivot
      // with element smaller than pivot
      // to sort in descending order
      // if (array[j] >= pivot)
      if (array[j] <= pivot) {

        // increase the second pointer if
        // smaller element is swapped with greater
        i = i + 1;
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }

    // put pivot in position
    // so that element on left are smaller
    // element on right are greater than pivot
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return (i + 1);
  }

  public void quickSort(int[] array, int low, int high) {
    if (low < high) {

      // Select pivot position and put all the elements smaller
      // than pivot on the left and greater than pivot on right
      int pi = partition(array, low, high);

      // sort the elements on the left of the pivot
      quickSort(array, low, pi - 1);

      // sort the elements on the right of pivot
      quickSort(array, pi + 1, high);
    }
  }

  // Driver code
  public static int test() {

    // create an unsorted array
    int[] data = new int[7];
    data[0] = 8;
    data[1] = 7;
    data[2] = 2;
    data[3] = 1;
    data[4] = 0;
    data[5] = 9;
    data[6] = 6;
    int size = data.length;

    Main qs = new Main();

    // pass the array with the first and last index
    qs.quickSort(data, 0, size - 1);


    for(int i = 0; i < size; i = i+1)
    {
      System.out.println(data[i]);
    }

    return 123;
  }
}
