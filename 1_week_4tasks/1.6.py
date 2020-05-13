import math
import time

start = time.time()

ite = 1
res = 0
logres = 0
prelogres = 0
i = 0
tst = 1
while ite < 10**10:
    i += 1
    res += 1 / ite
    ite += 1

print(res)

res = res - math.log(10**10, math.exp(1))
print(res)
end = time.time()
print("I'm test2, my execution time is " + str(end - start))
