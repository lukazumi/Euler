# Sieve of Eratosthenes (https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
numbers = list(range(2, 2000000))
numbers2 = list(range(2, 2000000))
rem = set()
for n in range(2, 2000000):
    if n*n > 2000000:
        break
    r_e = numbers2[::n]
    rem.update(numbers2[::n][1:])
    numbers2.remove(n)
numbers = [x for x in numbers if x not in rem]

s = sum(numbers)
print(s)

