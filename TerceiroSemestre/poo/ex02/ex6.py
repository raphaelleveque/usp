tmp = float(input())
max = min = tmp

while tmp != 0 :
    if tmp > max :
        max = tmp
    if tmp < min :
        min = tmp
    tmp = float(input())

print(f"Maior: {max}")
print(f"Menor: {min}")