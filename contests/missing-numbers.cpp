vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    vector<int> result;
    map<int, int> freqA, freqB;
    for(unsigned int i = 0; i < arr.size(); i++) {
        auto hit = freqA.find(arr[i]);
        if (hit == freqA.end()) {
            freqA.insert({arr[i], 1});
        } else {
            hit->second += 1;
        }
    }
    for(unsigned int i = 0; i < brr.size(); i++) {
        auto hit = freqB.find(brr[i]);
        if (hit == freqB.end()) {
            freqB.insert({brr[i], 1});
        } else {
            hit->second += 1;
        }
    }
    
    for (auto it = freqB.begin(); it != freqB.end(); it++) {
        int key = it->first;
        int val = it->second;
        auto hit = freqA.find(key);
        cout << key;
        if (hit == freqA.end()) {
            result.push_back(key);
            continue;
        }
        
        if(hit->second != val) {
            result.push_back(key);
            continue;
        }
    }
    return result;
}
