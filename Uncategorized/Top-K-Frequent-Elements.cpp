bool sortbysecdesc(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second>b.second;
}
class Solution {
    
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        map<int, int>::iterator itr;
        vector <int> result;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        vector<pair<int, int>> vec;

        map<int, int> :: iterator it2;
        for (it2=mp.begin(); it2!=mp.end(); it2++)
        {
            vec.push_back(make_pair(it2->first, it2->second));
        }
        sort(vec.begin(), vec.end(), sortbysecdesc);
        int cnt = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i].first << ": " << vec[i].second << endl;
            if(cnt < k) {
                result.push_back(vec[i].first);
                cnt++;
            }
        }

        return result;
    }
};