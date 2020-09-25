def main():
    ans = 0
    a = str(1 << 1000)
    for s in a:
        ans += int(s)
    print(ans)

if __name__ == "__main__":
    main()
