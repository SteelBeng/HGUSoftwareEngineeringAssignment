package pers.beng.experiment4;

public class Line
{
    OriginalPoint p1,p2;

    public Line(OriginalPoint p1, OriginalPoint p2)
    {
        this.p1 = p1;
        this.p2 = p2;
    }

    public double getLength()
    {
        return Math.sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
    }
}
