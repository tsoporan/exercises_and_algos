# Get the n-th prime, the range will be up to 10^4, uses sieve of eratosthenes.

class PrimeGenerator(object):
    def __init__(self, upto=10**4):
        self.all_nums = range(2, upto)
        self.primes = []

        self.generate()

    def generate(self):
        while self.all_nums:
            prime = self.all_nums.pop(0)
            self.primes.append(prime)

            for num in self.all_nums:
                if num % prime == 0:
                    self.all_nums.remove(num)

    def get_prime(self, n):
        """Return a the n-th prime."""
        if self.primes:
            return self.primes[n]

pg = PrimeGenerator()

print(pg.get_prime(0) == 2)
print(pg.get_prime(1) == 3)
print(pg.get_prime(9) == 29)
print(pg.get_prime(99) == 541)
