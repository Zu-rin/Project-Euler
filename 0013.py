def main():
    ans = 0
    for _ in range(100):
        n = int(input())
        ans += n
    print(str(ans)[:10])


if __name__ == "__main__":
    main()