
mod = int(1e9 + 7)


def no4_2col(n):

    def next_n(prevn):
        a0, a1, a2, a3 = prevn
        next_a0 = (a0 + a1 + a2 + a3) % mod
        next_a1 = a0
        next_a2 = a1
        next_a3 = a2
        return [next_a0, next_a1, next_a2, next_a3]

    st = [1, 0, 0, 0]
    for _ in range(n):
        st = next_n(st)

    # print(st)
    return sum(st)


def compute(n):
    return (n * no4_2col(n - 1) + no4_2col(n)) % mod


# for n in [100, 10000, 1000000, 10000007]:
    # print(compute(n))

print(compute(4))
print(compute(5))
