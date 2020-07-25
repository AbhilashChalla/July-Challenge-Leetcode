class Solution {
public:
    vector<int> convert(string ans){
        vector<int> int_ans;
        for(int i=0;i<ans.length();i++){
            int_ans.push_back(ans[i]-'0');
        }
        return int_ans;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int num_cells=cells.size(),day=1;
        unordered_map<string,int> m;
        vector<string> pattern_store;
        string pattern="";
        for (auto val:cells) pattern+=to_string(val);
        bool repeat=false;
        for(int i=1;i<=N && repeat==false;i++){
            string temp=pattern;
            for(int d=1;d<7;d++){
                if(temp[d-1]==temp[d+1])
                    pattern[d]='1';
                else
                    pattern[d]='0';
            }
            pattern[0]='0';
            pattern[7]='0';
            if(m.find(pattern)!=m.end())
            {
                repeat=true;
            }
            else{
                m.insert({pattern,day});
                pattern_store.push_back(pattern);
            }
            day++;
        }
        day=pattern_store.size();
        if(repeat==false)
            return convert(pattern);
        
        int req_day=(N%day);
        if (req_day==0) req_day=day;
        return convert(pattern_store[req_day-1]);
    }
};
