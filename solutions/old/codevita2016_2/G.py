import sys
try:
    inp = input()
    cs, bas = inp.strip().split('||')
    c = cs.split('|')
    b = list(map(int, bas[:-1]))
    a = int(bas[-1])
    
    added = [-1 for _ in range(10)]
    
    if len(c)!=10:
        raise
    for cv in c:
        val = int(cv[-1])
        for pos in map(int,cv[:-1]):
            added[pos]=val
    
    for cr in b:
        added[cr]+=10
    
    actual = []
    curr = a
    for v in added:
        if v==-1:
            continue
        actual.append(curr)
        curr = v-curr
    # print(added)
    # print(actual)
    chars = input().strip()
    if len(chars)!=10:
        sys.stdout.write('-1')
    elif len(set(chars))!=10:
        sys.stdout.write('-1')
    else:
        for v in actual:
            sys.stdout.write(chars[v])
except:
    sys.stdout.write('-1')