import numpy as np
import sys
import argparse


def run(nth_prime):
    # Sieve of Eratosthenes (https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
    numbers = list(range(1, 5000000))
    numbers2 = list(range(2, 5000000))
    rem = set()
    for n in range(2, 5000000):
        if n*n > 5000000:
            break
        r_e = numbers2[::n]
        rem.update(numbers2[::n][1:])
        numbers2.remove(n)
    numbers = [x for x in numbers if x not in rem]
    print(str(nth_prime) + "th prime:" + str(numbers[int(nth_prime)]))


def parse_arguments(argv):
    parser = argparse.ArgumentParser()
    parser.add_argument('-nth_prime', type=str, required=True)
    return parser.parse_args(argv)


if __name__ == "__main__":
    arg = parse_arguments(sys.argv[1:])
    run(arg.nth_prime)
