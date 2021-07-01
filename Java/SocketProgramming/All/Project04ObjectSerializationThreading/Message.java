import java.io.*;

/**
 * Message
 */
public class Message implements Serializable {

    Integer firstNumber = null;
    Integer secondNumber = null;
    Integer result = null;

    public Message(Integer firstNumber, Integer secondNumber) {
        this.firstNumber = firstNumber;
        this.secondNumber = secondNumber;
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