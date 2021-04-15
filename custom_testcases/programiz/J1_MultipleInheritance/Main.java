public class Main {

  protected Main(){}

  public static int test() {

    // create object of Language class
    Language java = new Language();

    java.connectServer();

    // call the inherited method of Frontend class
    java.responsive(java.language);

    return 123;
  }
}

