n = int(input())
c = list(map(float, input().split()))
s = 0
for i in c:
    s += pow(i, 3)
print(pow(s, 1/3))