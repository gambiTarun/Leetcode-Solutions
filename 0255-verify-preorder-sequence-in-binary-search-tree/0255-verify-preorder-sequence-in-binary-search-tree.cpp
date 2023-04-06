class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        stack<int> st;
        int curmin = 0;
        for(int x:preorder){
            if(x<curmin)
                return false;
            while(!st.empty() && st.top()<x){
                curmin = st.top();
                st.pop();
            }
            st.push(x);
        }
        return true;
    }
};