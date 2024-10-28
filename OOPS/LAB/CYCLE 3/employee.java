import java.util.*;
class employee {
    int age;
    long phone;
    String name, address;
    double salary;
    void printSal() {
        System.out.println("Salary: " + salary);
    }
}
class officer extends employee {
    String special;
}
class manager extends employee {
    String dep;
}
class empdetails {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        officer a = new officer();
        manager b = new manager();
        System.out.println("\tEnter the Officer's details");
        System.out.print("Enter The Name:");
        a.name = s.nextLine();
        System.out.print("Enter the Age:");
        a.age = s.nextInt();
        System.out.print("Enter the address:");
        s.nextLine();
        a.address = s.nextLine();
        System.out.print("Enter the phone number:");
        a.phone = s.nextLong();
        System.out.print("Enter the salary:");
        a.salary = s.nextDouble();
        System.out.print("Enter the Specialization:");
        s.nextLine();
        a.special = s.nextLine();
        System.out.println("\tEnter the Manager's details");
        System.out.print("Enter The Name:");
        b.name = s.nextLine();
        System.out.print("Enter the Age:");
        b.age = s.nextInt();
        System.out.print("Enter the address:");
        s.nextLine();
        b.address = s.nextLine();
        System.out.print("Enter the phone number:");
        b.phone = s.nextLong();
        System.out.print("Enter the salary:");
        b.salary = s.nextDouble();
        System.out.print("Enter the Department:");
        s.nextLine();
        b.dep = s.nextLine();
        System.out.println("\tThe details of the officer are:");
        System.out.println("Name:\t" + a.name);
        System.out.println("Age:\t" + a.age);
        System.out.println("Address:\t" + a.address);
        System.out.println("Phone number:\t" + a.phone);
        a.printSal();
        System.out.println("Specialization:\t" + a.special);
        System.out.println("The details of the Manager are:");
        System.out.println("Name:\t" + b.name);
        System.out.println("Age:\t" + b.age);
        System.out.println("Address:\t" + b.address);
        System.out.println("Phone number:\t" + b.phone);
        b.printSal();
        System.out.println("Department:\t" + b.dep);
    }
}
