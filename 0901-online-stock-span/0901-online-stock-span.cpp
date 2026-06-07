class StockSpanner {
public:

    stack<pair<int,int>> st;
    int idx;

    StockSpanner() {
        idx = -1;
    }

    int next(int price) {

        idx++;

        while(!st.empty() && price >= st.top().first) {
            st.pop();
        }

        int ans;

        if(st.empty()) {
            ans = idx + 1;
        }
        else {
            ans = idx - st.top().second;
        }

        st.push({price, idx});

        return ans;
    }
};