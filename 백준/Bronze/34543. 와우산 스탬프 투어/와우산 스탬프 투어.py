n = int(input()); w = int(input())

point = 0

point += n * 10
if n >= 3:
  point += 20
if n == 5:
  point += 50
if w > 1000:
  point = max(0, point - 15)

print(point)