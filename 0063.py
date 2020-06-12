def Judge(n, k):
    a = len(str(pow(n, k)))
    if a == k:
        return 1
    elif a < k:
        return 0
    else:
        return 2

def main():
    ans = 1
    for i in range(1, 1000):
        for j in range(2, 10):
            a = Judge(j, i)
            if a is 1:
                ans += 1
            elif a is 2:
                break
    print(ans)

if __name__ == "__main__":
    main()
