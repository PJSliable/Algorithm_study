import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int t = Integer.parseInt(st.nextToken());
    int m = Integer.parseInt(st.nextToken());

    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    if (m >= 45) {
      m -= 45;
    } else if (t > 0) {
      t -= 1;
      m = m + 60 - 45;
    } else {
      t = 23;
      m = m + 60 - 45;
    }


    bw.write(t + " " + m + "\n");
    bw.flush();
    bw.close();
  }
}
