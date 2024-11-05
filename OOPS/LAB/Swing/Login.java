import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class Login implements ActionListener 
{
    JLabel l1, l2,l3;
    JTextField t1, t2;
    JButton b1, b2;
    Login() 
    {
        JFrame f = new JFrame("Login Page");
        l1 = new JLabel("Username");
        l2 = new JLabel("Password");
        l3 = new JLabel();
        t1 = new JTextField(20);
        t2 = new JPasswordField(20);
        b1 = new JButton("Clear");
        b2 = new JButton("Login");

        JPanel p = new JPanel();
        p.add(l1);
        p.add(t1);
        p.add(l2);
        p.add(t2);
        p.add(b1);
        p.add(b2);
        p.add(l3);
        b1.addActionListener(this);
        b2.addActionListener(this);
        f.add(p);
        f.setSize(500, 300);
        f.show();
    }
    public void actionPerformed(ActionEvent e) 
    {
        String s = e.getActionCommand();
        if (s.equals("Clear")) 
        {
            t1.setText("");
            t2.setText("");
        } 
        else if (s.equals("Login")) 
        {
            String username = t1.getText();
            String password = t2.getText();
            String result="Welcome "+username+" & "+password;
            l3.setText(result);
            
        }
    }
    public static void main(String args[]) 
    {
        new Login();
    }
}

