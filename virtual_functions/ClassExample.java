class Base{

    protected int m_value;

Base()
{

}
    Base(int value) {
        m_value = value;
        System.out.println("Base : ");
    }

    public int getValue()
    {
        return m_value;
    }

    public String getClassName()
    {
        return "Base Class: ";
    }

    public void setValue(int value)
    {
        m_value = value;
    }
}

public class ClassExample extends Base  {

    ClassExample(int x){
        m_value = x;
    }

    public int getValue(){
        return m_value;
    }

    public String getClassName(){
        return "Derived class: ";
    }
    public void setValue(int y){
        m_value = y;
    }

    public static void main(String[] args) {

        System.out.println("saurabh");

        Base b = new ClassExample(7);
        ClassExample c = new ClassExample(5);

        System.out.println(c.getClassName()+c.getValue());
        System.out.println(b.getClassName()+b.getValue());
        
    }


}