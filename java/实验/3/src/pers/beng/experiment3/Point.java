package pers.beng.experiment3;

public class Point
{
    private float x, y;
    public Point()
    {
        this.x = 0;
        this.y = 0;
    }
    public Point(float x, float y)
    {
        this.x = x;
        this.y = y;
    }
    public void showPoint()
    {
        System.out.println("X:"+this.x+" Y:"+this.y);
    }
    public Point getMiddlePointBetweenTwoPoint(Point pointA,Point pointB)
    {
        Point pointMid = new Point((pointA.x+pointB.x)/2,(pointA.y+pointB.y)/2);
        return pointMid;
    }

    public float getX() { return x; }
    public float getY() { return y; }
    public void setX(float x) { this.x = x; }
    public void setY(float y) { this.y = y; }
}
