package Esercizio2.src;

import java.util.ArrayList;

public class Soluzione {
    
    public String longestPrefixString(ArrayList<String> listString) {
        int min = 0;
        String resulString = new String();
        for(String name : listString) {
            if(min < name.length()) 
                min = name.length();
        }

        
        
        return null;
    }

    public static void main(String[] args) {
        ArrayList<String> listString = new ArrayList<>();
        listString.add("apple");
        listString.add("ape");
        listString.add("aprli");
        listString.add("applied");

        for(int i = 0; i < listString.size(); i++)
            System.out.println(listString.get(i));

    }
}
