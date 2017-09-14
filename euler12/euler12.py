from functools import reduce

def factors(n):
    return set(reduce(list.__add__,
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

l = []
search_l = []
index = 1
while(len(l) < 500):
    search_l.append(index)
    search = sum(search_l)
    l = factors(search)
    index = index + 1

print(sum(search_l))

