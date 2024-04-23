
public class JavaStaticExample{

    static{

        // static block get executed first
        System.out.println("Loading Library...");
    }

    static float PI = 3.14f;
    static int Max_Number = 101;

    public static int getReverseNumber(int num) {
        int reverseNum = 0;
        int reminder = 0;
        while(num >0){
            reminder = num %10;
            reverseNum = reverseNum*10 + reminder;
            num = num/10;
        }
        return reverseNum;
    }



    public static void main(String[] args) {
        System.err.println("Sks...error");
        System.out.println("Reverse Number of 1234567 is "+getReverseNumber(1234567));
        //increase max number
        Max_Number++;
        System.out.println("Max Number is : "+Max_Number);
        MaxNumberCounter();
        System.out.println("Max Number is : "+Max_Number);

        // Static class exam,ple
        System.out.println(" direct accessing static class variable: "+TestStatic.ff+" "+TestStatic.mm+" "+ new TestStatic().kk );
        System.out.println("direct accessing static class method: "+TestStatic.getIntValue());
        // creating object of static class not good idea
        TestStatic test = new TestStatic();
        System.out.println(test.getFloatValue()+" "+test.getNumber());
    }




    public static void MaxNumberCounter(int maxNum) {
        maxNum = maxNum +11;
    }

    public static void MaxNumberCounter() {
        Max_Number = Max_Number +11;
    }


    public static class TestStatic{
        int kk = 10;
        static float ff = 32.67f;
        static int mm = 345;

        public float getFloatValue() {
            return ff;
        }

        public static int getIntValue() {
            return mm;
        }

        public  int getNumber() {
            return kk;
        }
    }
}