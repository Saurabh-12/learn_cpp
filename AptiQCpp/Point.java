public class Point
{
	private int m_x;
	private int m_y;

	public Point (int x, int y)
	{
		m_x = x;
		m_y = y;
	}

	public Point(Point pt)
        {
                m_x = pt.m_x;
                m_y = pt.m_y;
        }



	public static void main(String args[])
	{
		Point p1 = new Point(10,20);

		Point p2 = p1;

		if (p1 ==p2)
		{
			System.out.println("P1 and P2 are equals");
		}
	}
}
