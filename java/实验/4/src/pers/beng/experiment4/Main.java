package pers.beng.experiment4;

import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        System.out.println("@author 何雨彤420109070318");

        Scanner s = new Scanner(System.in);
        System.out.print("1.点类OriginalPoint\n请输入点的坐标x,y：");
        OriginalPoint p = new OriginalPoint(s.nextInt(),s.nextInt());
        p.showPoint();
        System.out.println("\n");

        System.out.print("2.圆类Circle\n请输入点的坐标及半径x,y,r：");
        Circle c = new Circle(s.nextInt(),s.nextInt(),s.nextInt());
        c.draw();
        System.out.println("Circumference："+c.calCircumference());
        System.out.println("Square："+c.calSquare());
        System.out.println();

        System.out.print("3.线段类Line\n请输入两个点的坐标x,y,x,y：");
        OriginalPoint p1 = new OriginalPoint(s.nextInt(),s.nextInt());
        OriginalPoint p2 = new OriginalPoint(s.nextInt(),s.nextInt());
        Line l = new Line(p1,p2);
        System.out.println("Length："+l.getLength());
        System.out.println();

        System.out.print("4.矩形类Rectangle\n请输入起始点的坐标及长宽x,y,chang,kuan：");
        Rectangle r = new Rectangle(s.nextInt(),s.nextInt(),s.nextInt(),s.nextInt());
        r.draw();
        System.out.println("Circumference："+r.calCircumference());
        System.out.println("Square："+r.calSquare());
        System.out.println();

        System.out.print("5.三角形类Triangle\n请输入起始点的坐标,两边及其夹角x,y,sideA,sideB,angle：");
        Triangle t = new Triangle(s.nextInt(),s.nextInt(),s.nextInt(),s.nextInt(),s.nextInt());
        t.draw();
        System.out.println("Circumference："+t.calCircumference());
        System.out.println("Square："+t.calSquare());
    }
}
