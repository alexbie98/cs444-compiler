public class Main {

  public Main(){}

  public static int test () {

    // create a string
    String name = "programiz";

    // create two substrings from name
    // first substring contains first letter of name
    // second substring contains remaining letters
    String firstLetter = name.substring(0, 1);
    String remainingLetters = name.substring(1, name.length());

    // change the first letter to uppercase
    Main.toUpper(firstLetter);

    // join the two substrings
    name = firstLetter + remainingLetters;
    System.out.println("Name: " + name);

    return 123;

  }

  public static void toUpper(String s){

      for (int i=0; i< s.length(); i = i+1){
          s.chars[i] = (char) (s.chars[i] + 'A' - 'a');
      }

      
  }
}