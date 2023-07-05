#!/usr/bin/python3
""" File of the making_change function """


def makeChange(coins, total):
    """ Given a pile of coins of differents values,
     determine the fewest number of coins needed
      to meet a given amount total """
    if total <= 0:
        return 0
    INF = float('inf')
    dp = [INF] * (total + 1)
    dp[0] = 0

    for coin in coins:
        for i in range(coin, total + 1):
            if dp[i - coin] != INF:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != INF else -1
