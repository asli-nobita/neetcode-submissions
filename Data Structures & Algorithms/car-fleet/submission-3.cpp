class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size(); 
        vector<pair<int,int>> vec; 
        for(int i=0;i<n;i++) { 
            vec.push_back({position[i],speed[i]}); 
        }
        stack<float> st; 
        sort(vec.begin(),vec.end()); 
        for(int i=n-1;i>=0;i--) { 
            auto [p,s]=vec[i]; 
            float tm=(target-p)/(float)s; 
            if(!st.empty() && tm<=st.top()) continue; 
            st.push(tm); 
        }
        return st.size(); 
    }
};

// vec = 0,1 1,2 4,2 7,1
// time = 10 4.5  3   3


// 1.33 1 