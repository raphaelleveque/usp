def best_price(days, costs):
    total_analysed_days: int = (days[-1] + 1)
    best_values_per_day = [0] * total_analysed_days
    for day in range(1, total_analysed_days):        
        if day in days:
            best_values_per_day[day] = min(
                best_values_per_day[max(day - 30, 0)] + costs[2],
                best_values_per_day[max(day - 7, 0)] + costs[1],
                best_values_per_day[max(day - 1, 0)] + costs[0]
            )
        else: best_values_per_day[day] = best_values_per_day[day - 1]
    return best_values_per_day[-1]

if __name__ == 'main':
    n = input()
    prices:list[int]
    for i in range(3):
        prices.append(int(input().split()))

    target_days: list[int]
    for i in range(n):
        target_days.append(int(input().split()))

    cheapest: int = best_price(target_days, prices)
    print(cheapest, end='')