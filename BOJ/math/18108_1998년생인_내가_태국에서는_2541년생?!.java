import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int a = Integer.parseInt(br.readLine());

    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    bw.write(String.valueOf(a-2541+1998));

    bw.flush();
    bw.close();
  }
}
