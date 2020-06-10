def func(n, a, b):
    if n > 1000:
        return 0
    if len(str(a)) > len(str(b)):
        return func(n + 1 , a + 2 * b, a + b) + 1
    else:
        return func(n + 1, a +2 * b, a + b)

def main():
    print(func(8,1393,985))

if __name__ == "__main__":
    main()
