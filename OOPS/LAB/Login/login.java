import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class Login implements ActionListener 
{
    JLabel l1, l2, welcomeLabel; 
    JTextField t1; 
    JPasswordField t2; 
    JButton b1, b2;
    Login() 
    {
        JFrame f = new JFrame("Login");
        l1 = new JLabel("Username: ");
        t1 = new JTextField(20);
        l2 = new JLabel("Password: ");
        t2 = new JPasswordField(20);
        b1 = new JButton("Submit");
        b2 = new JButton("Clear");
        welcomeLabel = new JLabel("");
        JPanel p = new JPanel();
        p.setLayout(new GridLayout(4, 2, 10, 10));
        p.add(l1);
        p.add(t1);
        p.add(l2);
        p.add(t2);
        p.add(b1);
        p.add(b2);
        p.add(welcomeLabel);
        b1.addActionListener(this);
        b2.addActionListener(this);
        f.add(p);
        f.setSize(500, 300);
        f.setLocationRelativeTo(null);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.show();
    }
    public void actionPerformed(ActionEvent e) 
    {
        String s = e.getActionCommand();
        if (s.equals("Submit")) {
            String username = t1.getText();
            char[] password = t2.getPassword();
            if (username.equals("avinash") && new String(password).equals("password1")) {
                welcomeLabel.setText("Welcome, " + username + "!");
            } 
            else {
                welcomeLabel.setText("Invalid username or password.");
            }
            t1.setText("");
            t2.setText("");
        } else if (s.equals("Clear")) {
            t1.setText("");
            t2.setText("");
            welcomeLabel.setText("");
        }
    }
    public static void main(String[] args) 
    {
        new Login(); 
    }
}

