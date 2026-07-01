class LFUCache {
public:
    int cap, minFreq;

    struct Node {
        int value;
        int freq;
    };

    unordered_map<int, Node> cache;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> pos;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int freq = cache[key].freq;

        // Remove key from current frequency list
        freqList[freq].erase(pos[key]);

        // If this was the last key with minFreq
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        // Increase frequency
        cache[key].freq++;

        // Insert into new frequency list (MRU)
        freqList[freq + 1].push_front(key);
        pos[key] = freqList[freq + 1].begin();
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        updateFreq(key);
        return cache[key].value;
    }

    void put(int key, int value) {
        if (cap == 0)
            return;

        // Key already exists
        if (cache.find(key) != cache.end()) {
            cache[key].value = value;
            updateFreq(key);
            return;
        }

        // Cache full
        if (cache.size() == cap) {
            int delKey = freqList[minFreq].back(); // LRU in minFreq
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            cache.erase(delKey);
            pos.erase(delKey);
        }

        // Insert new key
        cache[key] = {value, 1};
        freqList[1].push_front(key);
        pos[key] = freqList[1].begin();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */