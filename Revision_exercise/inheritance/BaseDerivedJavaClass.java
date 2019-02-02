class BaseDerivedJavaClass
{
    public static void main(String[] args) {


        //Base dObj = new Base();
        System.out.println("-----------------------------");
        Derived derivedObj = new Derived(6);
    }

}

class Base
{
    private int base_Id;

    public Base()
    {
        System.out.println("Base class constructor");
    }

    public Base(int id)
    {
        base_Id = id;
        System.out.println("Base class Parameter constructor");

    }

}

class Derived extends Base
{
    private int Derived_Id;

    public Derived(int id)
    {
        Derived_Id = id;
        System.out.println("Derived class constructor");
    }


}