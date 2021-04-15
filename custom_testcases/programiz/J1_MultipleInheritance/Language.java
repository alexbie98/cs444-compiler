// Language extends Frontend class
// Language implements Backend interface
public class Language extends Frontend implements Backend {

  protected Language(){}

  protected String language = "Java";

  public void connectServer() {
    System.out.println(language + " can be used as backend language.");
  }

  

}