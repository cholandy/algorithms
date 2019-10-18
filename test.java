
public class test {
    static void alla(int... v) {
        System.out.print(v.length + " : ");
        for (int x : v) {
            System.out.print(x + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        alla(1);
        alla(1, 2, 3);
        alla(1, 2, 3, 4, 5);
    }
}
