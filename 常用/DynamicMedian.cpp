struct DynamicMedian {
	priority_queue<int> down;
	priority_queue<int, vector<int>, greater<int>> up;
	DynamicMedian() {}
	void insert(int x) {
		if (down.empty() || x <= down.top()) {
			down.push(x);
		} else {
			up.push(x);
		}
		if (down.size() > 1 + up.size()) {
			up.push(down.top());
			down.pop();
		}
		if (up.size() > down.size()) {
			down.push(up.top());
			up.pop();
		}
	};
	double Ans() {
		if (up.size() + down.size() & 1) {
			return down.top();
		} else {
			return (down.top() + up.top()) / 2.0;
		}
	};
};