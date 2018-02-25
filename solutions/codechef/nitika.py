def initial(s):
    return s[0].upper() + '.'


def lastname(s):
    return s[0].upper() + s[1:].lower()

t = int(input())
for _ in range(t):
    s = input()
    s = s.split()
    s = [initial(n) for n in s[:-1]] + [lastname(s[-1])]
    s = ' '.join(s)
    print(s)
