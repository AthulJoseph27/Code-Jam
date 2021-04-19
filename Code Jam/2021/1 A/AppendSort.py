te = int(input())

for t in range(te):

    n = int(input())
    l = input().split()
    a = [int(i) for i in l]

    count = 0

    for i in range(1, len(a)):
        last = a[i-1]
        cur = a[i]

        if a[i] > a[i-1]:
            continue

        dl = len(str(last))
        dc = len(str(cur))

        mx = a[i]

        temp = dc

        while dc < dl:

            cur *= 10
            mx *= 10
            mx += 9
            dc += 1
            count += 1

        dc = temp

        if cur > a[i-1]:
            a[i] = cur
            continue

        if mx <= a[i-1]:
            a[i] = cur*10
            count += 1
            continue

        a[i] = a[i-1] + 1

    print("Case #"+str(t+1)+": "+str(count))
