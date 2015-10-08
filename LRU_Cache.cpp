#include <unordered_map>
#include <list>

using namespace std;

class LRUCache{
public:
	struct Cache
	{
		int key;
		int value;
		Cache(int k, int v) : key(k), value(v){}
	};

	LRUCache(int capacity) {
		m_capacity = capacity;
	}

	int get(int key) {
		if (m_map.find(key) == m_map.end())
			return -1;

		FlashCache(key);

		return m_map[key]->value;
	}

	void set(int key, int value) {
		if (m_map.find(key) == m_map.end())
		{
			if (m_LRU_Cache.size() >= m_capacity)
			{
				m_map.erase(m_LRU_Cache.back().key);
				m_LRU_Cache.pop_back();
			}
			m_LRU_Cache.push_front(Cache(key, value));
			m_map[key] = m_LRU_Cache.begin();
			return;
		}
		m_map[key]->value = value;
		FlashCache(key);
	}

private:
	void FlashCache(int key)
	{
		list<Cache>::iterator iter = m_map[key];
		int val = iter->value;
		m_LRU_Cache.erase(iter);
		m_LRU_Cache.push_front(Cache(key, val));
		m_map[key] = m_LRU_Cache.begin();
	}

private:
	list<Cache> m_LRU_Cache;
	unordered_map<int, list<Cache>::iterator> m_map;
	int m_capacity;
};
