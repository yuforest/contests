N, K = map(int, input().split())

dict = {}
for i in range(N):
  village, money = map(int, input().split())
  present = village in dict.keys()
  if not present:
    dict[village] = 0
  dict[village] += money

dict_sorted = sorted(dict.items())

ans = K

for row in dict_sorted:
  # print(row[0])
  # print(row[1])
  if row[0] > ans:
    break
  ans += row[1]

print(ans)