import java.io.*;

/**
 * Message
 */
public class Message implements Serializable {

    Integer firstNumber = null;
    Integer secondNumber = null;
    Integer result = null;

    public Message(Integer FirstNumber, Integer SecondNumber) {
        this.firstNumber = FirstNumber;
        this.secondNumber = SecondNumber;
    }

    public Integer getFirstNumber() {
        return firstNumber;
    }

    public Integer getSecondNumber() {
        return secondNumber;
    }

    public Integer getResult() {
        return result;
    }

    public void setResult(Integer result) {
        this.result = result;
    }
}