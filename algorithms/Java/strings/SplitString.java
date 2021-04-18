//Separate the strings such as in other group same letter does not repeat.
//Example abcdaef will give 5,1,1 from first 'a' to last 'a' one group and then remaining 2 letters from 1-1 group
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class SplitString {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the string");
		String s = sc.next();
		List<Integer> a = new ArrayList<Integer>();
		Map<Character, Integer> last = new HashMap<Character, Integer>();
		for (int i = 0; i < s.length(); i++) {
			last.put(s.charAt(i), i);
		}
		int p = 0, ctr = 0;
		for (int i = 0; i < s.length(); i++) {
			if (last.get(s.charAt(i)) > p)
				p = last.get(s.charAt(i));
			++ctr;
			if (i == p) {
				a.add(ctr);
				ctr = 0;
			}

		}
		for (Integer i : a) {
			System.out.println(i);
		}
		sc.close();
	}
}