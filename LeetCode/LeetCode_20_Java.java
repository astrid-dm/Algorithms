// The problem link : https://leetcode.com/problems/valid-parentheses/

// 1. 4ms, 41.7MB
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<Character>();
        for(char c : s.toCharArray()) {
            if(c == '(') st.push(')');
            else if(c == '[') st.push(']');
            else if(c == '{') st.push('}');
            else if(st.empty() || st.pop() != c) return false;
        }
        return st.empty();
    }
}

// 2. 4ms, 42MB
class Solution {
    public boolean isValid(String s) {
        char[] left = {'{', '[', '('};
        char[] right = {'}', ']', ')'};
        Stack<Character> stack = new Stack<>();
        
        for(char c : s.toCharArray()){
            boolean ch = false;
            for(int j=0; j<right.length; j++){
                if(right[j] == c){
                    if(stack.empty()) return false;
                    if(stack.peek()==left[j]){
                        stack.pop();
                        ch = true;
                    }
                    else return false;
                }
            }
            if(!ch) stack.push(c);
        }
        return stack.empty();
    }
}
