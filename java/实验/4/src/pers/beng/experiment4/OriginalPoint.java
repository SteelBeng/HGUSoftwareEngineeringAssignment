package pers.beng.experiment4;

public class OriginalPoint
{
    protected int x;
    protected int y;

    public OriginalPoint(int x, int y)
    {
        this.x=x;
        this.y=y;
    }

    public int getX() { return x; }
    public int getY() {
        return y;
    }
    public void setX(int x) { this.x = x; }
    public void setY(int y) {
        this.y = y;
    }

    protected void showPoint()
    {
        System.out.print("x:"+x+"  y:"+y);
    }
    protected void draw()
    {
        System.out.print("x:"+x+"  y:"+y);
    }
    protected double calSquare()
    {
        return 0d;
    }
    protected double calCircumference()
    {
        return 0d;
    }
}
