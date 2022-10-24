def minDistance(word1, word2):
    n = len(word1)
    m = len(word2)
    cache = [[0] * (m + 1) for _ in range(n + 1)]

    for i in range(m + 1):
        cache[0][i] = i
    for j in range(n + 1):
        cache[j][0] = j

    for i in range(n):
        for j in range(m):
            if word1[i] == word2[j]:
                cache[i+1][j+1] = cache[i][j]
            else:
                cache[i+1][j+1] = 1 + min(cache[i+1][j], cache[i][j+1], cache[i][j])
    return cache[n][m]


qtde = int(input())
for _ in range(qtde):
    str1 = input()
    str2 = input()
    print(minDistance(str1, str2))
