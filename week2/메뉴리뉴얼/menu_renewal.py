
orders = ['abcfg','ac','cde','acde','bcfg','acdeh']

course = [2,3,4]

answer = []
subsets = []

for order in orders:
    arr = list(order)
    
    sub = [[]]

    for char in arr:
        size = len(sub)

        for i in range(size):
            sub.append(sub[i]+[char])
    
    subsets += sub

for j in course:
    temp = []

    for subset in subsets:
        if len(subset) == j:
            temp.append(subset)
        # print(temp)

    count_list = []

    # for x in temp:
    #     count_list.append(temp.count(x))
    
    # print(temp[count_list.index(max(count_list))])

    max_v = max(temp, key = temp.count)
    max_v = ''.join(max_v)

    answer.append(max_v)

print(answer)




