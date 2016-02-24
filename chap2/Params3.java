public class Params3 {
    public static void main(String[] args) {
        int[] n = new int[1];
        n[0] = 0;
        changeN(n);
        System.out.println(n);
    }

    public static void changeN(int[] n) {
        n[0] = 5;
    }
}

