import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class Calculator 
{
    private static double num1 = 0, num2 = 0, result = 0;
    private static String operator = "";
    public static void main(String[] args) 
    {
        JFrame frame = new JFrame("Calculator");
        JTextField textField = new JTextField();
        JPanel panel = new JPanel();
        String[] buttons = 
        {
            "7", "8", "9", "/",
            "4", "5", "6", "*",
            "1", "2", "3", "-",
            "0", ".", "=", "+"
        };

        frame.setSize(500, 600);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        textField.setBounds(20, 20, 460, 50);
        textField.setFont(new Font("Arial", Font.PLAIN, 24));
        textField.setHorizontalAlignment(SwingConstants.RIGHT);
        textField.setEditable(false);
        frame.add(textField);
        panel.setBounds(20, 80, 460, 480);
        panel.setLayout(new GridLayout(5, 4, 10, 10));
        frame.add(panel);
        for (String label : buttons) 
        {
            JButton button = new JButton(label);
            button.addActionListener(new ActionListener() 
            {
                public void actionPerformed(ActionEvent e) 
                {
                    String text = textField.getText();
                    if (label.equals("=")) 
                    {
                        num2 = Double.parseDouble(text);
                        switch (operator) 
                        {
                            case "+": result = num1 + num2; break;
                            case "-": result = num1 - num2; break;
                            case "*": result = num1 * num2; break;
                            case "/": result = num1 / num2; break;
                        }
                        textField.setText(String.valueOf(result));
                        operator = "";
                    } 
                    else if (label.equals("/") || label.equals("*") || label.equals("-") || label.equals("+")) 
                    {
                        num1 = Double.parseDouble(text);
                        operator = label;
                        textField.setText("");
                    } else {
                        textField.setText(text + label);
                    }
                }
            });

            panel.add(button);
        }

        frame.setVisible(true);
    }
}

