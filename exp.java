PROGRAM:
import java.io.*;
import
java.util.Scanner; class
Employee
{
int Emp_id,Mobile_no;
String Emp_name,address,Mail_id;
Scanner get=new
Scanner(System.in); public
Employee()
{
System.out.println("Enter name of the
Employee:");
 Emp_name=get.nextLine();
System.out.println("Enter Mail id of the Employee:"); 
Mail_id=get.nextLine();
System.out.println("Enter address of the
Employee:"); address=get.nextLine();
System.out.println("Enter Emp id:");
Emp_id=get.nextInt();
System.out.println("Enter Mobile No:");
Mobile_no=get.nextInt();
}
void display()
{
System.out.println("Employee id:"+Emp_id); System.out.println("Employee
name:"+Emp_name); System.out.println("Employee Mobile Number"+Mobile_no);
System.out.println("Employee mail:"+Mail_id);
System.out.println("Employee
address:"+address);
}
}