class HashTable{
private:
	int tableSize;
	vector<HashNode*> hashTable;
	inline int hashFcn(string key){
		return key.length() % tableSize;
	}
public: 
	HashTable(){
		tableSize = 16;
		hashTable.resize(tableSize);
		for(int i = 0; i < tableSize; ++i)
			hashTable[i] = new HashNode("", 0);
	}
	void insert(string key, int val){
		int index = hashFcn(key);
		HashNode* cur = hashTable[index];
		while(cur->next && cur->key != key)
			cur = cur->next;
		if(!cur->next)
			cur->next = new HashNode(key, val);
		else if(cur->key == key)
			cur->val = val;
		
	}
	bool find(string key){
		int index = hashFcn(key);
		HashNode* cur = hashTable[index]->next;
		while(cur && cur->key != key)
			cur = cur->next;
		return cur != NULL;
	}
	void erase(string key){
		int index = hashFcn(key);
		HashNode *cur = hashTable[index]->next, *pre = hashTable[index], *next;
		while(cur && cur->key != key){
			pre = cur;
			cur = cur->next;
		}
		if(cur){
			HashNode* temp = cur;
			pre->next = cur->next;
			delete temp;
		}
	}
	int get(string key){
		int index = hashFcn(key);
		HashNode *cur = hashTable[index];
		while(cur && cur->key != key)
			cur = cur->next;
		return cur ? cur->val : INT_MIN;
	}
};
