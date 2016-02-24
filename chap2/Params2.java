public class Params2 {
    public static void main(String[] args) {
        IntContainer n = new IntContainer(0);
        changeN(n);
        System.out.println(n);
    }

    public static void changeN(IntContainer n) {
        n.setN(5);
    }
}

