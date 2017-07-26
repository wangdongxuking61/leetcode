class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums)
	{
		int n = nums.size() ;

		vector<pair<int, int> > vec;
		vector<int> nums_size(n);
		for (int i = 0; i < n; i++)
		{
			nums_size[i] = nums[i].size();
			for (int j = 0; j < nums[i].size(); j++)
				vec.push_back(make_pair(nums[i][j], i));
		}
		sort(vec.begin(), vec.end());

		int nn = vec.size() , d= INT32_MAX, ret_a, ret_b;
		for (int i = 0; i < nn; i++)
		{
			vector<int> _nums_size = nums_size;

			int j = nn - 1;
			for (; j > i; --j)
			{
				if (_nums_size[vec[j].second] - 1 <= 0)
					break;
				else
					--_nums_size[vec[j].second];
			}
			if (vec[j].first - vec[i].first < d)
			{
				d = vec[j].first - vec[i].first;
				ret_a = vec[i].first;
				ret_b = vec[j].first;
			}

			if (nums_size[vec[i].second] - 1 <= 0)
				break;
			else
				--nums_size[vec[i].second];
		}

		return { ret_a, ret_b };
	}
};
