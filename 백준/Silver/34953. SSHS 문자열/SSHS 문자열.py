n = int(input())
if n <= 3:
    print("S" * n)
else:
    p = n // 3
    q = n % 3
    print("SSH" * p + "S" * q)