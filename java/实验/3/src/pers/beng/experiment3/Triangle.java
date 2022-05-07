package pers.beng.experiment3;

public class Triangle
{
    private int x;
    private int y;
    private static double a;

    public Triangle(int x,int y,double a)
    {
        this.x = x;
        this.y = y;
        this.a = a;
    }

    public double square()
    {
        double s = 0.5*x*y*Math.sin(a*Math.PI/180);
        return s;
    }
    public void setA(double a)
    {
        this.a = a;
    }
}
