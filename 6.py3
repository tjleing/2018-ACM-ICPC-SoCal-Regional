n = int(input())


def min_base(s1);
    max = 1
    for i in range(len(s1)):
        base = int(s1[i], 36)
        if base >  max:
            max = base
    return max

def are_same(s1, s2):
    min_base_1 = min_base(s1)
    min_base_2 = min_base(s2)
    for b1 in range(min_base_1 + 1, 37):
        for b2 in range(min_base_2 + 1, 37):
            if int(s1, b1) == int(s2, b2):
                return True
    return False
for i in range(n):
    inq = input().split(" ")
    s1 = inq[0]
    s2 = inq[1]
    if are_same(s1, s2):
        print("yes")
    else:
        print("no")

