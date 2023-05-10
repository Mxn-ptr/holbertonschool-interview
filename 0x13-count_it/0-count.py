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
    res = requests.get(url, headers=headers, allow_redirects=False, params=params)
    if res.status_code != 200:
        return
    
    data = res.json().get('data')
    posts = data.get('children')
    after = data.get('after')

    for word in word_list:
        word = word.lower()
    
    for post in posts:
        title = post['data']['title'].lower()
        for word in word_list:
            if word in title:
                if word in counts:
                    counts[word] += 1
                else:
                    counts[word] = 1
    
    if after is not None:
        count_words(subreddit, word_list, after, counts)
    else:
        sorted_count = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for k, v in sorted_count:
            if v > 0:
                print("{}: {}".format(k, v))
