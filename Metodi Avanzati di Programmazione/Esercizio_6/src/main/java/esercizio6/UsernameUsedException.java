package esercizio6;

public class UsernameUsedException extends Exception {
    String username;

    public UsernameUsedException(String username) {
        this.username = username;
    }

    @Override
    public String getMessage() {
        return "The username \"" + username + "\" has already been taken";
    }
}
