#include "cache.h"

Cache::Cache(int capacity)
      :_capacity(capacity) {
    _lru.clear();
    _cache.clear();
}

bool
Cache::_is_cache_full(void) {
    return _cache.size() == _capacity;
}

void
Cache::_evict_last_entry(void) {
    K key = _lru.back();
    _lru.pop_back();
    _cache.erase(key);
}

void
Cache::_update_entry(MIT &it) {
    _lru.erase(it->second.second);
    _touch_entry(it->first, it->second);
}

void
Cache::_touch_entry(const K& key, V &pair) {
    _lru.insert(_lru.begin(), key);
    pair.second = _lru.begin();
}

int
Cache::get_key(K key) {
    int res = -1;
    auto it = _cache.find(key);
    if (it != _cache.end()) {
        res = it->second.first;
        _update_entry(it);
    }
    return res;
}

int 
Cache::set_key(K key, int value) {
    auto it = _cache.find(key);
    if (it != _cache.end()) {
        it->second.first = value;
        _update_entry(it);
        return 0;
    } else {
        if (_is_cache_full()) {
            _evict_last_entry();
        }
        V v1 = V(value, _lru.begin());
        _touch_entry(key, v1);
        _cache.emplace(key, v1);
    }
    return 0;
}
