namespace PrimeTable {
	std::vector<int> primes;
	std::vector<int> minp;
	std::vector<bool> is_prime;
	void primes_init(int n) {
		minp.resize(n + 1);
		is_prime.resize(n + 1, true);
		is_prime[0] = is_prime[1] = false;
		for (int i = 2; i <= n; i++) {
			if (is_prime[i]) {
				primes.push_back(i);
				minp[i] = i;
			}
			for (int j = 0; primes[j] * i <= n; j++) {
				is_prime[primes[j] * i] = false;
				minp[primes[j] * i] = primes[j];
				if(i % primes[j] == 0) break;
			}
		}
	}
	bool IsPrime(int n) {
		if (n <= 1) return false;
		return is_prime[n];
	}
}
using namespace PrimeTable;