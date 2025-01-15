import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int a = Integer.parseInt(br.readLine());
    int b = Integer.parseInt(br.readLine());

    StringBuilder sb = new StringBuilder();
    sb.append(a*(b%10)).append("\n").append(a*((b/10)%10)).append("\n").append(a*((b/100)%10)).append("\n").append(a*b).append("\n");

    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    bw.write(String.valueOf(sb));
    bw.flush();

    bw.close();
  }
}
