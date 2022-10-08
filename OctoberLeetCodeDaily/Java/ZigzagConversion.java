public class ZigzagConversion {
    public String convert(String s, int numRows) {
        if(numRows == 1) return s;
        String arr[] = new String[numRows];
        for(int i=0;i<arr.length; i++) arr[i] = "";
        String result = new String();
        int ptr = 0;
        boolean des = false;
        for(int i=0; i<s.length(); i++){
            arr[ptr]+= s.charAt(i);
            if(ptr==numRows-1)des = true;
            if(ptr == 0) des = false;
            if(des) ptr--;
            else ptr++;
        }
        for(int i=0; i<arr.length;i++) result += arr[i];
        return result;
    }
}
