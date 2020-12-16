#!/usr/bin/python3
"""
Recursive function that queries the Reddit API,
parses the title of all hot articles, and prints a sorted (list)
count of given keywords.
"""
import collections
import sys
from requests import get


def count_words(subreddit, word_list, after=None, word_match={}):
    """
    recursive function parses titles and prints them in a sorted
    count of given key words
    Note: imported lIbraries must be in alphabetical order
    :param subreddit: posts dedicated to a specific topi people write about
                        on reddit
    :param word_list: list of words
    :after: next page
    :word_match: list of word frequency
    :return: word, word_count
    """
    # get list of hot articles
    # if not word_list:
    # return None
    try:
        req_data = get("https://www.reddit.com/r/{}/hot.json"
                       .format(subreddit),
                       headers={'User-Agent': 'mindz'},
                       allow_redirects=False,
                       params={'after': after})

        req_dict = req_data.json()

        if word_match == {}:
            for words in word_list:
                word_match[words] = 0
        after = req_dict['data']['after']

        # parse the words in the data list
        for pos in range(len(req_dict['data']['children'])):
            parWord_list = req_dict['data']['children'][pos]['data']['title']
            iterateList = parWord_list.split()

            # get the words from the word list
            for word in parWord_list:
                for wi in word_list:
                    if wi.lower() == word.lower():
                        word_match[wi] += 1
        # order list
        if after is None:
            wordMatch_Dict = collections.OrderedDict(sorted(word_match.items(),
                                                            key=lambda x: x[1],
                                                            reverse=True))
            flag = 0
            for pal, w_count in wordMatch_Dict.items():
                if w_count != 0:
                    print("{}: {}".format(pal, w_count))
                else:
                    flag += 1
            if flag == len(wordMatch_Dict):
                print()
            # recursive part
        else:
            count_words(subreddit, word_list, after, word_match)
    except Exception:
        pass
