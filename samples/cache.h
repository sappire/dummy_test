#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;
typedef int K;
typedef std::pair<int, list<int>::iterator> V;
typedef unordered_map<K,V>::iterator MIT;

class Cache {
public:
    Cache(int capacity);
    int get_key(K key);
    int set_key(K key, int value);
private:
    void _update_entry(MIT &it);
    void _touch_entry(const K& key, V &it);
    void _evict_last_entry(void);
    bool _is_cache_full(void);
    int _capacity;
    list<K> _lru;
    unordered_map<K,V> _cache;
};
