import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int a = Integer.parseInt(br.readLine());
    int b = Integer.parseInt(br.readLine());

    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    boolean x = a > 0;
    boolean y = b > 0;
    int ans = 3;
    if (x && y) {
      ans = 1;
    } else if (x && !y) {
      ans = 4;
    } else if (!x && y) {
      ans = 2;
    }
    bw.write(ans+ "\n");
    bw.flush();
    bw.close();
  }
}
