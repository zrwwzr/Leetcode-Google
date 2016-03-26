class HashEntry{
public:
	string key;
	int val;
	int deleted;
	HashEntry(string k, int v) : key(k), val(v), deleted(false){};
};

class DeletedEntry : public HashEntry{
private:
	static DeletedEntry *inst;
	DeletedEntry() : HashEntry("", -1) {};
public:
	static DeletedEntry *instance(){
		if(!inst)
			inst = new DeletedEntry();
		return inst;
	}
};

DeletedEntry *DeletedEntry::inst = NULL;
class HashTable{
private:
	HashEntry **table;
	size_t size;
	int f(string key){
		int idx = 0;
		for(int i = 0; i < key.length(); ++i)
			idx = (31 * idx + key[i]) % size;
		return idx;
	}
public:
	HashTable(){
		size = 8;
		table = new HashEntry*[size];
		//initialize hash table
		for(int i = 0; i < size; ++i)
			table[i] = NULL;
	}
	~HashTable(){
		for(int i = 0; i < size; ++i)
			if(table[i] && table[i] != DeletedEntry::instance())
				delete table[i];
	}
	HashEntry* get(string key){
		int hash = -1, probe = f(key);
		while(probe != hash && (table[probe] == DeletedEntry::instance() || (table[probe] && table[probe]->key != key))){
			if(hash == -1) hash = probe;
			probe = (probe + 1) % size;
		}
		//probing hits an empty slot or probing back to the start position
		//means key is not in the table
		if(!table[probe] || hash == probe)
			return NULL;
		return table[probe];
	}
	void insert(string key, int val){
		int hash = -1, probe = f(key), deleted = -1;
		while(probe != hash && (table[probe] == DeletedEntry::instance() || (table[probe] && table[probe]->key != key))){
			if(hash == -1) hash = probe; //store the initial position
			if(table[probe] == DeletedEntry::instance())
				deleted = probe; //store the possible slot but keeps probing since the key maybe already exist
			probe = (probe + 1) % size; //linear probing
		}
		//didn't find the key
		if((!table[probe] || probe == hash) && deleted != -1)
			table[deleted] = new HashEntry(key, val);
		else if(probe != hash){
			//duplicate key
			if(table[probe] != DeletedEntry::instance() && table[probe] && table[probe]->key == key)
				table[probe]->val = val;
			else
				table[probe] = new HashEntry(key, val);
		}
	}
	void erase(string key){
		int hash = -1, probe = f(key);
		//continue search when we encounter a deleted instance
		while(probe != hash && (table[probe] == DeletedEntry::instance() || (table[probe] && table[probe]->key != key))){
			if(hash == -1) hash = probe;
			probe = (probe + 1) % size;
		}
		if(probe != hash && table[probe]){
			delete table[probe];
			table[probe] = DeletedEntry::instance();
		}
	}
	void printTable(){
		for(int i = 0; i < size; ++i){
			if(table[i])
				cout<<"key: "<<table[i]->key<<" val: "<<table[i]->val<<endl;
			else
				cout<<endl;
		}
	}
};
