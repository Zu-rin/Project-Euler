def Judge(num):
    s = str(num)
    t = s[::-1]
    n = int(s) + int(t)
    for _ in range(49):
        s = str(n)
        t = s[::-1]
        if s == t:
            return False
        n = int(s) + int(t)
    return True

def main():
    ans = 0
    for i in range(1, 10000):
        if Judge(i):
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()
