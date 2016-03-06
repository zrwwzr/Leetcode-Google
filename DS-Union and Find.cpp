//implementation of Weighting Quick-Union with Path Compression
class Union_Find{
public:
	Union_Find(int n){
		parents.resize(n, 0);
		size.resize(n, 1);
		for(int i = 0; i < n; ++i)
			parents[i] = i;
	}
	//check if x and y have the same parents
	bool Find(int x, int y){
		return Parent(x)  == Parent(y);
	}
	//set the parent of x's root to the parent of y's or vice versa depends on the parents size
	void Union(int x, int y){
		int px = Parent(x), py = Parent(y);
		//optimization 1: weighting, linking smaller tree under the larger one
		if(size[px] < size[py]){
			parents[px] = py;
			size[py] += size[px];
		}else{
			parents[py] = px;
			size[px] += size[py];
		}
	}
private:
	vector<int> parents;
	vector<int> size;
	//find the parent of x and compress the path
	int Parent(int x){
		while(x != parents[x]){
			//optimization 2: path compression, make every other node in path point to its grandfather
			parents[x] = parents[parents[x]];
			x = parents[x];
		}
		return x;
	}
};
