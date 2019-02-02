class JavaVirtualTest
{
    public static void main(String[] args) {

        Base baseObj = new Base("B");
        Derived derivedObj = new Derived("D");

        baseObj.getName();
        derivedObj.getName();
        System.out.println("---------------------------------");

        baseObj = derivedObj;
        baseObj.getName();
        
    }
}

class Base {
    String name;

     Base(String name)
    {
        this.name = name;

    }

    public void getName()
    {
        System.out.println("Base Name: "+name);
    }
}

class Derived extends Base
{
    String name;

    Derived(String name)
    {
        super(name);
        this.name = name;

    }

    public void getName()
    {
        System.out.println("Derived Name: "+name);
    }
}
