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
    int time = Integer.parseInt(br.readLine());
    int addHour = 0;
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    m += time;
    if (m >= 60) {
      while (m >= 60) {
        addHour += 1;
        m -= 60;
      }
      t += addHour;
      if (t >= 24) {
        while (t >= 24) {
          t -= 24;
        }
      }
    }

    bw.write(t + " " + m + "\n");
    bw.flush();
    bw.close();
  }
}
