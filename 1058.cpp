class Solution {
public:
    string minimizeError(vector<string>& prices, int target) {
        int sum = 0;
        float sumf = 0.0;
        int alter = 0;
        for (string ps:prices){
            float pf = stof(ps);
            sum += floor(pf);
            sumf += pf;
            if (ceil(pf)!=floor(pf)) alter++;
        }
        if (target>=sum && target<=sum+alter){
            int n = target-sum;
            vector<float> sf;
            for (string ps:prices){
                float pf = stof(ps);
                if (ceil(pf)!=floor(pf))
                    sf.push_back(ceil(pf)-pf);
            }
            if (n>0) nth_element(sf.begin(), sf.begin()+n, sf.end());
            float ret = 0.0;
            for (int i = 0;i < alter;i++){
                if (i<n) ret += sf[i];
                else ret+=ceil(sf[i])-sf[i];
            }
            string r = to_string(round(ret*1000)/1000);
            return r.substr(0, r.find('.')+4);
        }
        else return to_string(-1);
    }
};