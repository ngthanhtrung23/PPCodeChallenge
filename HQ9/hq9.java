import java.io.*;
import java.util.*;
import java.math.*;

class hq9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String prog = sc.nextLine();
        for(int x = 0; x < prog.length(); ++x) {
            char c = prog.charAt(x);
            if (c == 'H') {
                System.out.println("Hello, World!");
            }
            else if (c == 'Q') {
                System.out.println(prog);
            }
            else if (c == '9') {
                for(int i = 99; i >= 1; --i) {
                    String bottle = "bottle";
                    if (i > 1) bottle += "s";

                    System.out.println(i + " " + bottle + " of beer on the wall,");
                    System.out.println(i + " " + bottle + " of beer.");
                    System.out.println("Take one down, pass it around,");
                    
                    if (i == 1) {
                        System.out.println("No bottles of beer on the wall.");
                    }
                    else if (i == 2) {
                        System.out.println("1 bottle of beer on the wall.");
                    }
                    else {
                        System.out.println((i-1) + " bottles of beer on the wall.");
                    }
                    if (i > 1) System.out.println();
                }
            }
            else {
                // just ignore it
            }
        }
        sc.close();
    }
}
