public class ConvertIntAsStringToSting {


    public static void main(String[] args) {

        int result = convertStringToInt("345");
        System.out.println(result);
        
    }



    public static int convertStringToInt(String str) {
        int result = 0;
        int multiply = 1;

        for (int i = str.length()-1; i >= 0; i--) {
            /*
             * convert character into integer in java
             * Method 1
             * int a = ch - '0';
             * 
             * Method 2
             * int a = Integer.parseInt(String.valueOf(ch));
             * 
             * Method 3
             * Using getNumericValue() method of Character Class
             * int a = Character.getNumericValue(ch);
             * 
             */
            result = result + (str.charAt(i)- '0') * multiply;
            multiply = multiply *10;
        }

        return result;
    }
}