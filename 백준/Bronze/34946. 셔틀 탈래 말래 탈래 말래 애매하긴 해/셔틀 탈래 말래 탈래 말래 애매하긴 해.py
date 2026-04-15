a, b, c, d = map(int,input().split())
shuttle = (a + b <= d)
walk = (c <= d)

if (shuttle and walk):
    print("~.~")
elif (not shuttle and not walk):
    print("T.T")
elif shuttle:
    print("Shuttle")
else:
    print("Walk")