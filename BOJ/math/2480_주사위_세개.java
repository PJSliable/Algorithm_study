import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Main1 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    int c = Integer.parseInt(st.nextToken());

    Map<Integer, Integer> map = new HashMap<>();
    addToMap(map, a);
    addToMap(map, b);
    addToMap(map, c);
    int ans = findKeyWithMaxValue(map);

    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    bw.write(ans + "\n");
    bw.flush();
    bw.close();
  }

  private static void addToMap(Map<Integer, Integer> map, int key) {
    map.put(key, map.getOrDefault(key, 0) + 1);
  }

  private static int findKeyWithMaxValue(Map<Integer, Integer> map) {
    int maxKey = 0;
    int maxValue = 0;
    int sameKey = 0;
    for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
      if (entry.getValue() >= maxValue) {
        maxValue = entry.getValue();
        if (entry.getKey() > maxKey) {
          maxKey = entry.getKey();
        }
      }
      if (entry.getValue() == 2) {
        sameKey = entry.getKey();
      }
    }
    if (maxValue == 3) {
      return 10000 + maxKey * 1000;
    } else if (maxValue == 2) {
      return 1000 + sameKey * 100;
    } else {
      return maxKey * 100;
    }
  }
}

