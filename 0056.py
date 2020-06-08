def main():
    ans = 0
    for a in range(1, 100):
        for b in range(1, 100):
            s = sum(list(map(int, str(pow(a, b)))))
            ans = max(ans, s)
    print(ans)

if __name__ == "__main__":
    main()
