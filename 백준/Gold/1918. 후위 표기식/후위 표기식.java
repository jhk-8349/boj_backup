import java.io.*;

class Main {
    public static void main(String[] args) {
        String expr;
        char[] s = new char[1_000_000];
        int top = -1;

        try {
            BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter wr = new BufferedWriter(new OutputStreamWriter(System.out));    

            expr = rd.readLine();
            
            for (int i = 0; i < expr.length(); i++) {
                char c = expr.charAt(i);

                if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) wr.write(c);
                else if (c == ')') {
                    while (s[top] != '(') wr.write(s[top--]);
                    top--;
                } else {
                    while (top != -1 && isHigher(s[top], c)) wr.write(s[top--]);
                    s[++top] = c;
                }
            }
            
            while (top != -1) wr.write(s[top--]);

            wr.flush();
            wr.close();
        }

        catch (Exception e) {
            System.out.println(e);
        }
    }

    public static boolean isHigher(char top, char x) {
        if (top == '(') return false;
        else if (top == '+' || top == '-') return (x == '+' || x == '-');
        else return (x != '(');
    }
}