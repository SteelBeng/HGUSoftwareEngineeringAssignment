package pers.beng.experiment3;

public class Student
{
    private String name;
    private Date birth;
    private String sex;
    private String ID;
    private String phone;
    private String department;
    private Date enrollment;
    private String address;

    public Student()
    {
        this.name = "暂无信息";
        this.birth = new Date();
        this.sex = "男";
        this.ID = "暂无信息";
        this.phone = "暂无信息";
        this.department = "暂无信息";
        this.enrollment = new Date();
        this.address = "暂无信息";
    }
    public Student(String name,Date birth,String sex,String ID,String phone,String department,Date enrollment,String address)
    {
        this.name = name;
        this.birth = birth;
        this.sex = sex;
        this.ID = ID;
        this.phone = phone;
        this.department = department;
        this.enrollment = enrollment;
        this.address = address;
    }

    public void print()
    {
        System.out.println("姓名："+name);
        System.out.println("生日："+birth.year+"-"+birth.month+"-"+birth.day);
        System.out.println("性别："+sex);
        System.out.println("身份证号："+ID);
        System.out.println("手机号码："+phone);
        System.out.println("所在学院："+department);
        System.out.println("入校时间："+enrollment.year+"-"+enrollment.month+"-"+enrollment.day);
        System.out.println("家庭地址："+address);
    }
    public void compareBirth(Student s1,Student s2)
    {
        if(s1.birth.compare(s2.birth)==0)
        {
            System.out.println(s1.name+"和"+s2.name+"一般大");
        }
        else if(s1.birth.compare(s2.birth)==1)
        {
            System.out.println(s1.name+"比"+s2.name+"大");
        }
        else
        {
            System.out.println(s1.name+"比"+s2.name+"小");
        }
    }
    public boolean compareID(Student s1,Student s2)
    {
        return s1.ID==s2.ID;
    }
    public void introduce()
    {
        System.out.println("大家好，我是"+department+"学院的"+name+"!");
    }

}
