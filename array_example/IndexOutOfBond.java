
public class IndexOutOfBond {


    public static void main(String[] args) {
        System.out.println("Array Index out of Bound Example");

        int [] arr = new int[10];

        System.err.println(" Array size "+arr.length);

        arr[1] = 12;
        arr[2] = 13;
        arr[9] = 23;
        //arr[10] = 26; // array index out of bond; we can handle it by using try catch block

        try {
            arr[10] = 26;
        } catch(ArrayIndexOutOfBoundsException e) {
           e.printStackTrace();
        }

        for (int kk : arr) {
            System.out.print(" "+kk+" ");
        }
        System.err.println(" ");

    }

}