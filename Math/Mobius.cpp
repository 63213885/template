namespace Mobius {
	std::vector<int> primes;
	std::vector<int> mobius;
	std::vector<bool> is_prime;
	
	void MobiusInit(int n) {
		mobius.resize(n + 1);
		is_prime.resize(n + 1, true);
		is_prime[0] = is_prime[1] = false;
		mobius[1] = 1;
		for (int i = 2; i <= n; i++) {
			if (is_prime[i]) {
				primes.push_back(i);
				mobius[i] = -1;
			}
			for (int j = 0; primes[j] * i <= n; j++) {
				is_prime[primes[j] * i] = false;
				if (i % primes[j] == 0) {
					mobius[primes[j] * i] = 0;
					break;
				}
				mobius[primes[j] * i] = mobius[i] * -1;
			}
		}
	}
}
using namespace Mobius;