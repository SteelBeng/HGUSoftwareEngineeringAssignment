package pers.beng.experiment4;

public class Circle extends OriginalPoint
{
    private int r;

    public Circle(int x, int y, int r)
    {
        super(x,y);
        this.r=r;
    }

    public void draw()
    {
        this.showPoint();
        System.out.println("  r:"+r);
    }
    public double calSquare()
    {
        return Math.PI*r*r;
    }
    public double calCircumference()
    {
        return Math.PI*r;
    }
}
