def all_subsets(acc=0, i=0):
    global minimo
    if i == len(apples):
        minimo = min(minimo, abs(total - 2*acc))
        return

    all_subsets(acc + apples[i], i+1)
    all_subsets(acc, i+1)

n = int(input())
apples = [int(x) for x in input().split()]
total = sum(apples)
minimo = float('inf')

all_subsets()
print(minimo)
