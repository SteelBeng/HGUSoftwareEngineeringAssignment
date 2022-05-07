package pers.beng.experiment4;

public class Triangle extends OriginalPoint
{
    private int sideA;
    private int sideB;
    private int angle;

    public Triangle(int x,int y,int sideA,int sideB,int angle)
    {
        super(x,y);
        this.sideA = sideA;
        this.sideB = sideB;
        this.angle = angle;
    }

    public void draw()
    {
        this.showPoint();
        System.out.print("  sideA："+sideA+"  sideB："+sideB+"  angle："+angle);
        System.out.println();
    }
    public double calSquare()
    {
        return 0.5*sideA*sideB*Math.sin(angle*Math.PI/180);
    }
    public double calCircumference()
    {
        return sideA+sideB+Math.sqrt(sideA*sideA+sideB*sideB);
    }
}
