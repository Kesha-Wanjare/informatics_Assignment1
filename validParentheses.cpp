class Solution {
public:
    bool isValid(string s) {
        stack<char> v;
        bool valid = true;
        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                    case '(':
                        v.push('(');
                        break;
                    case '[':
                        v.push('[');
                        break;
                    case '{':
                        v.push('{');
                        break;
                    case ']':
                        if(!v.empty() && v.top() == '['){
                            v.pop();
                        }else{
                            v.push(']');
                        }
                        break;
                    case ')':
                        if(!v.empty() && v.top() == '('){
                            v.pop();
                        }else{
                            v.push(')');
                        }
                        break;
                    case '}':
                        if(!v.empty() && v.top() == '{'){
                            v.pop();
                        }else{
                            v.push('}');
                        }
                        break;
                    default:
                        break;
            }
        }if(v.empty()){
            return true;
        }else{
            return false;
        }
    }
};
