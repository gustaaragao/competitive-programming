def solve():
    n = int(input())
    print(2**n - 1)
    hanoi(1, 3, n)

def hanoi(start, end, n):
    if n == 1:
        print(start, end)
        return

    helper = 6 - (start + end)
    hanoi(start, helper, n-1)
    print(start, end)
    hanoi(helper, end, n-1)

solve()
