public class Main {

  protected Main(){}

  public static int test() {

    // create an object of LinkedList
    Node lst = new Node(1);

    // assign values to each linked list node
    Node second = new Node(2);
    Node third = new Node(3);

    // connect each node of linked list to next node
    lst.next = second;
    second.next = third;

    // printing node-value
    System.out.print("LinkedList: ");
    while (lst != null) {
      System.out.print(lst.value + " ");
      lst = lst.next;
    }
      System.out.println();

    return 123;
  }

}