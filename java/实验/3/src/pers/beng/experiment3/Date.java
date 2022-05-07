package pers.beng.experiment3;

public class Date
{
    public int year;
    public int month;
    public int day;

    public Date(int year,int month,int day)
    {
        this.year = year;
        this.month = month;
        this.day = day;
    }
    public Date()
    {
        this.year = 1900;
        this.month = 1;
        this.day = 1;
    }

    public int compare(Date d)
    {
        if(year<d.year)
        {
            return 1;
        }
        else if(month<d.month)
        {
            return 1;
        }
        else if(day<d.day)
        {
            return 1;
        }
        else if(day==d.day)
        {
            return 0;
        }
        else
            return 2;
    }
}
