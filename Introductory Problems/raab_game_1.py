

a = int(input())
while a > 0:
    b,c,d = map(int, input().split())
    # prior check if c + d exceeds b then simply no
    if c + d > b:
        print("NO")
    else:
        # dp is that a[i]  == b[i] 
        dp = b - c - d
        ans = [0] * (b + 1)
        for i in range(d + 1, d + dp + 1):
            ans[i] = i
        U = []
        for x in range(1, b + 1):
            if not (d + 1 <= x <= d + dp):
                U.append(x)
        # Not used are in U 
        L, R = 0, len(U) - 1
        ok = True
        for i in range(d, 0, -1):
            if U[R] > i:
                ans[i] = U[R]
                R -= 1
            else:
                ok = False
                break
                
        if ok:
            for i in range(d + dp + 1, b + 1):
                if U[L] < i:
                    ans[i] = U[L]
                    L += 1
                else:
                    ok = False
                    break
        if not ok:
            print("NO")
        else:
            print("YES")
            for i in range(1, b + 1):
                print(i, end=" ")
            print()
            for i in range(1, b + 1):
                print(ans[i], end=" ")
            print()
    
    a-=1