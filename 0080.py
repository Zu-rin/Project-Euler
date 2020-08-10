from decimal import *

getcontext().prec = 200
ans = 0
for i in range(101):
    if not (i ** 0.5).is_integer():
        r = Decimal(str(i)) ** Decimal("0.5")
        s = '{:.150f}'.format(r).replace(".", "")
        d = [int(i) for i in s]
        ans += sum(d[:100])

print(ans)
