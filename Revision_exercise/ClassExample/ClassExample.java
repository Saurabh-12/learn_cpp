class ClassExample
{

    private  double m_length = 1.0; // m_length has a default value of 1.0
    private double m_width = 1.0; // m_width has a default value of 1.0

    public ClassExample()
    {
        
    }

    public ClassExample(double length, double width)
    {
        m_length = length;
        m_width = width;
    }

    public void print()
    {
        System.out.println(" Rectangle Length "+m_length+" Width "+m_width);
    }


    public static void main(String[] args) {

        ClassExample obj1 = new ClassExample();
        obj1.print();

        
    }
}