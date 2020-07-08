def Search(d):
    if d is 100:
        return 1, 1
    x, y = Search(d + 1)
    if d % 3 is 0:
        a = 2 * d / 3 * y + x
    else:
        a = y + x
    return y, a

if __name__ == "__main__":
    a, b = Search(2)
    a += b * 2
    ans = 0
    for c in str(int(a)):
        ans += int(c)
    print(ans)
