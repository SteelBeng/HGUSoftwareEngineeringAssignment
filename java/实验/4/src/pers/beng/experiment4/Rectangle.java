package pers.beng.experiment4;

public class Rectangle extends OriginalPoint
{
    private int chang;
    private int kuan;

    public Rectangle(int x, int y, int chang, int kuan)
    {
        super(x,y);
        this.chang = chang;
        this.kuan = kuan;
    }
    public void draw()
    {
        this.showPoint();
        System.out.print("  chang："+chang+"  kuan："+kuan);
        System.out.println();
    }

    public double calSquare()
    {
        return chang*kuan;
    }
    public double calCircumference()
    {
        return (chang+kuan)*2;
    }
}
