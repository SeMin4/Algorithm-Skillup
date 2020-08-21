import java.util.HashMap;

class Word{
    Word[] words;
    HashMap<Integer, Integer> stringCnt;
    public Word(){
        stringCnt = new HashMap<>();
        words = new Word[26];
    }
}
public class Main {

    public static void main(String[] args) {
	// write your code here
        String[] words = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
        String[] queries = {"fro??", "????o", "fr???", "fro???", "pro?", "?????"};
        int[] answer = solution(words, queries);
        for (int i = 0; i < answer.length; i++) {
            System.out.print(answer[i] + " ");
        }
        System.out.println();
    }

    public static int[] solution(String[] words, String[] queries) {
        int[] answer;
        answer = new int[queries.length];
        Word preRoot = new Word();
        Word sufRoot = new Word();
        for (int i = 0; i < words.length; i++) {
            String tmp = words[i];
            preMakeTree(preRoot, tmp);
            sufMakeTree(sufRoot, tmp);
        }
        for (int i = 0; i < queries.length; i++) {
            int type = queryType(queries[i]);
            switch (type){
                case -1:
                    String reverseQuery = new StringBuilder(queries[i]).reverse().toString();
                    answer[i] = findMakeTree(sufRoot, reverseQuery);
                    break;
                case 0:
                    answer[i] = preRoot.stringCnt.get(queries[i].length()) == null ? 0 : preRoot.stringCnt.get(queries[i].length());
                    break;
                case 1:
                    answer[i] = findMakeTree(preRoot, queries[i]);
                    break;
            }
        }
        return answer;
    }
    public static void preMakeTree(Word root, String word){
        Word pointer = root;
        int length = word.length();
        Integer strCnt = pointer.stringCnt.get(length);
        if(strCnt == null){
            pointer.stringCnt.put(length, 1);
        }else{
            pointer.stringCnt.put(length, strCnt + 1);
        }
        for (int i = 0; i < word.length(); i++) {
            pointer = getWord(word, pointer, i);
        }
    }
    public static void sufMakeTree(Word root, String word){
        Word pointer = root;
        for (int i = word.length() - 1; i >= 0; i--) {
            pointer = getWord(word, pointer, i);
        }
    }
    public static Word getWord(String word, Word pointer, int i) {
        int length = word.length();
        if(pointer.words[word.charAt(i) - 'a'] != null){
            pointer = pointer.words[word.charAt(i) - 'a'];
            Integer strCnt = pointer.stringCnt.get(length);
            if(strCnt == null){
                pointer.stringCnt.put(length, 1);
            }else{
                pointer.stringCnt.put(length, strCnt + 1);
            }
        }else{
            pointer.words[word.charAt(i) -'a'] = new Word();
            pointer = pointer.words[word.charAt(i) - 'a'];
            pointer.stringCnt.put(length, 1);
        }
        return pointer;
    }
    public static int queryType(String query){
        if(query.charAt(0) == '?' && query.charAt(query.length() - 1) == '?'){
            return 0;//전부 ?임
        }
        else if(query.charAt(0) == '?'){
            return -1;//앞부분이 물음표임
        }
        else{
            return 1;
        }
    }
    public static int findMakeTree(Word root, String query){
        int i = 0;
        Word pointer = root;
        for (char checkChar = query.charAt(i); checkChar != '?'; checkChar = query.charAt(i)) {
            pointer = pointer.words[checkChar - 'a'];
            if(pointer == null){
                return 0;
            }
            i += 1;
        }
        Integer ret = pointer.stringCnt.get(query.length());
        return ret == null ? 0 : ret;
    }
}
