class ClassExample2
{
    static int m_value = 0;


    public static void main(String[] args) {
        
        ClassExample obj = new ClassExample();

        ClassExample2 obj1 = new ClassExample2();
        obj1.m_value = 2;
        ClassExample2 obj2 = new ClassExample2();

        System.out.println("obj1 Value: "+obj1.m_value);
        System.out.println("obj2 Value: "+obj2.m_value);
    }

    static double pow(double x, int n) {
        if (n == 0)	return 1;
        double half = pow(x, n / 2);
        if (n % 2 == 0)	return half * half;
        else if (n > 0)	return half * half * x;
        else	return half * half / x;
        }

}