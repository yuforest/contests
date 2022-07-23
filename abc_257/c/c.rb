

n, x  = gets.split(" ")
n = n.to_i
x = x.to_i
a = []
b = []
n.times do |i|
  val1, val2 = gets.split(" ")
  a.append(val1.to_i)
  b.append(val2.to_i)
end
dp = []
n.times do
  tmp = []
  10001.times do
    tmp.append(false)
  end
  dp.append(tmp)
end

dp[0][0] = false

(1..n).each do |i|
  (1..10000).each do |j|
    if (dp[i-1][j-a[i-1]] == true) && j - a[i-1] >= 0 && j-a[i-1] <= n
      dp[i][j] = true
    end
    if dp[i-1][j-b[i-1]] == true && j - b[i-1] >= 0 && j-b[i-1] <= n
      dp[i][j] = true
    end
  end
end

puts dp[n][x]
if dp[n][x] == true
  puts "Yes"
else
  puts "No"
end