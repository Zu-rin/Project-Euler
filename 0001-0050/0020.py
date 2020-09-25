def main():
    k = 1
    for i in range(1, 101):
        k *= i
    ans = 0
    for c in str(k):
        ans += int(c)

    print(ans)

if __name__ == "__main__":
    main()
