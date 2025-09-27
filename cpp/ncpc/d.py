
path = [0] * 100000000
p = -1

def back(cc, cd):
    global p
    if cc == a and cd == b:
        return 1
    
    if cc < a and cd < b:
        return 0

    if cc < 0 or cd < 0:
        return 0
    
    if cc < cd:
        p = p + 1
        path[p] = 0
        return back(cc, cd - cc)
    elif cd < cc:
        # print(path[p])
        p = p + 1
        path[p] = 1
        return back(cc - cd, cd)
    
    return 0

tc = int(input())

while tc > 0:
    tc = tc - 1
    a, b, c, d = [int(_) for _ in input().split()]

    p = -1

    res = 1

    if back(c, d):
        for i in range(p, -1, -1):
            # print(i, path[i])
            if path[i]:
                res = res * 2 + 1
            else:
                res = res * 2
        
        print(res)
    else:
        print(-1)
