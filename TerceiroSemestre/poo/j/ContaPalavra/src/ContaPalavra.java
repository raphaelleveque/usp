import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class ContaPalavra {
	public TreeMap<String, Integer> map;
	public Scanner fileSC;
	
	public ContaPalavra(String filename) throws FileNotFoundException {
		File file = new File(filename);
		this.fileSC = new Scanner(file);
	}
	
	public void criaMapa() {
	    map = new TreeMap<>();
	    String temp;
	    while (fileSC.hasNext()) {
	    	temp = fileSC.next();
	    	String firstletter = temp.substring(0, 1).toUpperCase();
	        String nameCapitalized = firstletter + temp.substring(1);

	    	
	    	int freq;
	    	if (map.get(nameCapitalized) == null) {
	    		freq = 0;
	    	} else {
	    		freq = map.get(nameCapitalized);
	    	}
	    	
	    	map.put(nameCapitalized, freq + 1);
	    }
	}
	
	public void mostraMapa() {
        // using for-each loop for iteration over Map.entrySet()
        for (Map.Entry<String,Integer> entry : map.entrySet()) 
            System.out.println(entry.getKey() + ": " + entry.getValue());
	}
	
}
