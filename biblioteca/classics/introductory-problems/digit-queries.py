from math import ceil

def solve():
    t = int(input())

    for _ in range(t):
        n = int(input())
        k = 0

        while n - 9*(10**k)*(k+1) >= 0:
            n -= 9*(10**k)*(k+1)
            k += 1

        start = 10 ** k - 1
        jump = n // (k + 1)

        if n % (k + 1) != 0:
            jump += 1

        number = str(start + jump)
        print(number[(n % (k + 1)) - 1])

solve()
