

import java.util.Iterator;
import java.util.Stack;
import java.util.Vector;

class Balanced_Paranthesis {

    public void problem(String input_string){

        Vector<String> output = new Vector<>();

        Stack<Character> sta = new Stack<>();

        for(int i = 0;i < input_string.length();i++){
            for (int j = 0; j <= i; j++){
                String sub_s = input_string.substring(j,i+1);
                char[] sub = sub_s.toCharArray();
                int no_of_left_paranthesis = 0;
                int no_of_right_paranthesis = 0;
                for (int k = 0;k < sub_s.length();k++){
                    if(sub[k] == '('){
                        no_of_left_paranthesis = no_of_left_paranthesis + 1;
                        sta.push('(');
                    }
                    if(sub[k] == ')'){
                        no_of_right_paranthesis = no_of_right_paranthesis + 1;
                        sta.pop();
                    }

                    if (sub_s.length() % 2 == 0 && no_of_left_paranthesis == no_of_right_paranthesis && sta.isEmpty()){
                        output.add(sub_s);
                    }
                    else{
                        while (!sta.isEmpty()){
                            sta.pop();
                        }
                    }
                }
            }

            int length = 0;
            if (output.size() == 0){
                System.out.println(length + " ");
            }
            else{
                int max_len = 0;
                String long_Str = "";

                for(int s = 0;s < output.size();s++){
                    if (output.get(s).length() > max_len){
                        max_len = output.get(s).length();
                        long_Str = output.get(s);
                    }
                }
                System.out.println("Maximum length of string : " + max_len + "and the string is : " + long_Str);
            }
        }
    }
}

class Main {

    public static void main(String[] args){
        Balanced_Paranthesis bal = new Balanced_Paranthesis();
        bal.problem("((()))");
    }
}

