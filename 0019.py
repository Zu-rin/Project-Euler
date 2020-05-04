import datetime

def NextMonth(dt):
    dt += datetime.timedelta(days = 31)
    while dt.day > 1:
        dt -= datetime.timedelta(days = 1)
    return dt

def main():
    ans = 0
    dt = datetime.date(1901, 2, 1)
    while dt.year < 2001:
        if (dt - datetime.date(1901, 1, 6)).days % 7 is 0:
            print(dt)
            ans += 1
        dt = NextMonth(dt)

    print(ans)

if __name__ == "__main__":
    main()
