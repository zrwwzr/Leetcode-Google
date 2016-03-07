class Solution {
public:
    int searchColumn(int l, int h, vector<vector<char>> &image, bool opt){
    	int i, m;
    	while(l < h){
    		m = (l + h) / 2;
    		for(i = 0; i < image.size(); ++i)
    			if(image[i][m] == '1') break;
    		if(i != image.size() == opt)
    			h = m;
    		else l = m + 1;
    	}
    	return l;
    }
    int searchRow(int l, int h, vector<vector<char>> &image, bool opt){
    	int i, m;
    	while(l < h){
    		m = (l + h) / 2;
    		for(i = 0; i < image[0].size(); ++i)
    			if(image[m][i] == '1') break;
    		if(i != image[0].size() == opt)
    			h = m;
    		else l = m + 1;
    	}
    	return l;
    }
    int minArea(vector<vector<char>>& image, int x, int y) {
    	if(image.empty()) return 0;
    	const size_t m = image.size(), n = image[0].size();
    	int left = searchColumn(0, y, image, true);
    	int right = searchColumn(y + 1, n, image, false);
    	int top = searchRow(0, x, image, true);
    	int bottom = searchRow(x + 1, m, image, false);
    	return (right - left) * (bottom - top);
    }
};
