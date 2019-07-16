def perm(l):
    # Compute the list of all permutations of l
    if len(l) <= 1:
        return [l]
    r = []
    for i in range(len(l)):
        s = l[:i] + l[i+1:]
        p = perm(s)
        for x in p:
            r.append(l[i:i+1] + x)
    return r


print(perm([1, 2, 3]))
print(perm((1, 2, 3)))

str = "123456"
print(str.count("345"))
