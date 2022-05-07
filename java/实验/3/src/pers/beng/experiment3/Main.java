package pers.beng.experiment3;

import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {

        System.out.println("@author 何雨彤420109070318");

        /*Point*/
        System.out.println("1.Point类相关操作");
        Point pointA = new Point(12,5);
        System.out.print("A点坐标为：");
        pointA.showPoint();

        Point pointB = new Point();
        System.out.print("请输入想要设置的B点坐标为：");
        Scanner s=new Scanner(System.in);
        pointB.setX(s.nextInt());
        pointB.setY(s.nextInt());

        Point pointMid = new Point();
        pointMid = pointMid.getMiddlePointBetweenTwoPoint(pointA, pointB);
        System.out.print("两点中点为：");
        pointMid.showPoint();
        System.out.println();

        /*Triangle*/
        System.out.println("2.Triangle类相关操作");
        Triangle t1=new Triangle(3,4,90);
        Triangle t2=new Triangle(6,8,90);

        System.out.print("第一个三角形面积为：");
        System.out.println(t1.square());
        System.out.print("第二个三角形面积为：");
        System.out.println(t2.square());

        System.out.print("请输入希望将第一个三角形修改为的角度：");
        t1.setA(s.nextInt());
        System.out.print("修改后的面积为：");
        System.out.println(t1.square());
        System.out.println();

        /*Student*/
        System.out.println("3.Student类相关操作");
        Date d1=new Date(2002,10,1);
        Date d2=new Date(2021,9,1);
        Date d3=new Date(2003,9,5);
        Date d4=new Date(2022,9,1);
        Student s1 = new Student("张三",d1,"男","130302000000000000","13000000000","信息工程",d3,"石家庄市");
        Student s2 = new Student("李四",d2,"男","430300000000000000","15000000000","信息工程",d3,"唐山市");

        System.out.println("当前学生信息为：");
        s1.print();
        System.out.println();
        s2.print();

        System.out.println();
        System.out.print("比较两人的年龄大小：");
        s1.compareBirth(s1,s2);
        System.out.print("比较两人是否是同一人：");
        boolean b = s1.compareID(s1,s2);
        System.out.println(b);

        System.out.print("自我介绍：");
        s1.introduce();
    }
}
