#!/usr/bin/python3
""" File of the making_change function """

def makeChange(coins, total):
    """ Given a pile of coins of differents values,
     determine the fewest number of coins needed
      to meet a given amount total """
    if total <= 0:
        return 0
    coins.sort(reverse=True)
    i = 0
    numb_coins = 0

    while (i < len(coins) and total > 0):
        if (total - coins[i]) >= 0:
            total -= coins[i]
            numb_coins += 1
        else:
            i += 1

    if (total > 0 and numb_coins > 0):
        return -1
    else:
        return numb_coins
