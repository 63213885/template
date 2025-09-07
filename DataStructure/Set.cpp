struct Set {
	std::priority_queue<ll> a, b;
	void push(ll x) {
		a.emplace(x);
	}
	void erase(ll x) {
		b.emplace(x);
	}
	ll top() {
		while (!b.empty() && a.top() == b.top()) {
			a.pop();
			b.pop();
		}
		return a.top();
	}
};