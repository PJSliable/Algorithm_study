import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder(br.readLine());
    sb.append("??!");

    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    bw.write(String.valueOf(sb));
    bw.flush();
    bw.close();
  }
}
