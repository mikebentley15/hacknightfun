/**
 * This was taken from the internet and used to compare answers with my
 * implementation.
 * 
 * This was modified to match the same style of output and allowing to suppress
 * the permutation output.
 */
public class paren {
    public static int matches;
    public static void main(String[] args) {
        java.util.Vector<String> argList = new java.util.Vector<String>();
        for (int i = 0; i < args.length; i++)
          argList.add(args[i]);
        boolean toPrint = true;
        if (argList.contains("-q")) {
          argList.remove("-q");
          toPrint = false;
        }
        brackets(Integer.valueOf(argList.elementAt(0)), toPrint);
    }
    static void brackets(final int N, boolean toPrint) {
        System.out.println("Pairs:        " + N);
        brackets(N, 0, 0, new char[N * 2], toPrint);
        System.out.println("Permutations: " + matches);
    }
    static void brackets(int openStock, int closeStock, int index, char[] arr, boolean toPrint) {
        while (closeStock >= 0) {
            if (openStock > 0) {
                arr[index] = '(';
                brackets(openStock-1, closeStock+1, index+1, arr, toPrint);
            }
            if (closeStock-- > 0) {
                arr[index++] = ')';
                if (index == arr.length) {
                    matches++;
                    if (toPrint) {
                        System.out.println(arr);
                    }
                }
            }
        }

    }
}
