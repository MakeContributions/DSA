import java.util.ArrayList;
import java.util.List;

public class tokenizer{

    public static boolean charIsDelimiter(char c, char [] delimiters){
        //verrify if a character is a delimiter
        for(char d: delimiters)
            if(c == d) return true;
        
        return false;
    }

    public static List<String> tokenize(String str, char... delimiters){
        //by default the delimiter is white space ' '
        if(delimiters.length <= 0) delimiters = new char [] {' '};

        List<String> tokens = new ArrayList<String>();
		String token  = "";

		for(int i = 0; i < str.length(); i++) {
			char pos = str.charAt(i);

			if(!charIsDelimiter(pos, delimiters)) {
                //if the character is not a delimiter add it into the current token
				token += pos;
			}else {
                //avoid an empty token before adding to the list
				if(!token.equals(""))
					tokens.add(token);
				
                token = "";
			}
		}

        //add the last token to the list
		tokens.add(token);

		return tokens;
    }

    public static void printTokens(List<String> tokens){
        if(tokens == null) return;

        System.out.print("[ ");
        for(String token : tokens){
            System.out.print("'" + token + "', ");
        }
        System.out.println("]");
    }

    public static void main(String  [] args){
        String myString = "Hello     I like pasta & pizza--hut";

        System.out.println("myString = '" + myString + "'");

        System.out.print("\ntokenize(myString) = ");
        printTokens(tokenize(myString));

        System.out.print("\ntokenize(myString, ' ', 'z') = ");
        printTokens(tokenize(myString, ' ', 'z'));

        System.out.print("\ntokenize(myString, 'p','l', 'u') = ");
        printTokens(tokenize(myString, 'p','l', 'u'));

        System.out.print("\ntokenize(myString, ' ', '&', '-') = ");
        printTokens(tokenize(myString, ' ', '&', '-'));
    }
}

/*
    to call the function:
        tokenize(str, delimiters)
        str is a text
        delimiters is a list of char which is by default white space : ' '
        example: 
            tokenize("hello world") = tokenize("hello world", ' ') = [ 'hello', 'world' ]
            tokenize("hello world", ' ', 'l') = [ 'he', 'o', 'wor', 'd' ]


    to run this file:
        javac tokenizer.java
        java tokenizer

    result:
        myString = 'Hello     I like pasta & pizza--hut'

        tokenize(myString) = [ 'Hello', 'I', 'like', 'pasta', '&', 'pizza--hut', ]

        tokenize(myString, ' ', 'z') = [ 'Hello', 'I', 'like', 'pasta', '&', 'pi', 'a--hut', ]

        tokenize(myString, 'p','l', 'u') = [ 'He', 'o     I ', 'ike ', 'asta & ', 'izza--h', 't', ]

        tokenize(myString, ' ', '&', '-') = [ 'Hello', 'I', 'like', 'pasta', 'pizza', 'hut', ]
            
*/
