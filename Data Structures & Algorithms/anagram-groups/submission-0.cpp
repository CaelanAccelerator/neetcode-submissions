class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> map;
        vector<vector<string>> res;
        int i = 0;
        for(auto &str : strs){
            string strSorted = str;
            sort(strSorted.begin(),strSorted.end());
            if(!map.contains(strSorted)){
                res.push_back({});
                res.back().push_back(str);
                map[strSorted] = res.size() - 1;
            }
            else{
                int index = map[strSorted];
                if(index >= res.size()){
                    cout<<"wrong index"<<endl;
                    return {{"wrong"}};
                }
                res[index].push_back(str);
            }
        }
        return res;
    }
};
