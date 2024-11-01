// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        String bomb = br.readLine();
        
        Stack<Character> stack = new Stack<>();
        for (int i=0; i<s.length(); i++) {
            stack.push(s.charAt(i));
            
            if (stack.size() >= bomb.length()) {
                boolean flag = true;
                for (int j=0; j<bomb.length(); j++) {
                    if (stack.get(stack.size() - bomb.length() + j) != bomb.charAt(j)) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    for (int k=0; k<bomb.length(); k++) {
                        stack.pop();
                    }
                }
            }
        }
        
        StringBuilder sb = new StringBuilder();
        while (!stack.empty()) {
            sb.append(stack.peek());
            stack.pop();
        }
        System.out.println(
            sb.length() == 0 ? "FRULA" : sb.reverse());
    }
}