#!/usr/bin/python3
""" Defines recursive function """
import requests


def count_words(subreddit, word_list, after=None, counts={}):
    """ queries the Reddit API, parses the title of all hot articles,
    and prints a sorted count of given keywords
    (case-insensitive, delimited by spaces)"""
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'My_Agent'}
    params = {'after': after}
    res = requests.get(url, headers=headers, allow_redirects=False,
                       params=params)
    if res.status_code != 200:
        return

    data = res.json().get('data')
    posts = data.get('children')
    after = data.get('after')

    for post in posts:
        title = post['data']['title'].lower().split()
        for word in word_list:
            word = word.lower()
            n = title.count(word)
            counts[word] = counts.setdefault(word, 0) + n

    if after is not None:
        count_words(subreddit, word_list, after, counts)
    else:
        sorted_count = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for k, v in sorted_count:
            if v > 0:
                print("{}: {}".format(k, v))
