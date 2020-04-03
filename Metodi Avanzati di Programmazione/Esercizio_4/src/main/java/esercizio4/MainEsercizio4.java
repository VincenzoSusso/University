package esercizio4;

import java.util.HashMap;
import java.util.Map;

public class MainEsercizio4 {

    public static void main(String[] args) {

        //-------------------------------------
        Map<String, Integer> m = new HashMap<String, Integer>();

        for(String arg: args[0].split(" ")) {
            Integer count = m.get(arg);
            m.put(arg, (count == null) ? 1 : count + 1);
        }

        for (Map.Entry<String, Integer> e : m.entrySet()) {
            System.out.println(e.getKey() + ": " + e.getValue());
        }
    }
}
