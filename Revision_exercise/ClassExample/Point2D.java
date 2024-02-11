import java.lang.Math;

class Point2D
{
    private double m_x = 0.0;
    private double m_y = 0.0;

    public Point2D(double x, double y)
    {
        m_x = x;
        m_y = y;
    }
    public Point2D()
    {

    }

    public void print()
    {
        System.out.println("Point2D ( "+m_x+" "+m_y+" )");
    }

    public double distance(Point2D obj1, Point2D other)
    {
        return Math.sqrt((obj1.m_x - other.m_x) * (obj1.m_x - other.m_x) +
         (obj1.m_y - other.m_y) * (obj1.m_y - other.m_y));
    }


    public static void main(String[] args) {
        
        Point2D first = new Point2D();
        Point2D second = new Point2D(3.0, 4.0);

        first.print();
        second.print();

        System.out.println("Distance between two points: "+first.distance(first, second));

    }
}