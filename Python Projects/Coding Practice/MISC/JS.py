#import Counter for multiset counts
from collections import Counter

#import re for tokenization
import re

#import typing for type hints
from typing import Iterable, Callable

# tokens are for strings
def tokenize(text: str) -> list:
    #Simple tokenizer: extract word tokens, lowercase.
    return re.findall(r'\w+', text.lower())

def jaccard_tokens(s1: str, s2: str, tokenizer: Callable[[str], list] = None) -> float:
    #Jaccard on token sets from two strings (default whitespace/word tokens).
    if tokenizer is None:
        tokenizer = tokenize
    return jaccard_sets(tokenizer(s1), tokenizer(s2))

# Jaccard for sets without duplicates and strings
def jaccard_sets(a: Iterable, b: Iterable) -> float:
    #Jaccard similarity for two sets/iterables (ignores duplicates).
    sa, sb = set(a), set(b)
    if not sa and not sb:
        return 1.0
    inter = sa & sb
    union = sa | sb
    return len(inter) / len(union)

def jaccard_multiset(a: Iterable, b: Iterable) -> float:
    #Jaccard for multisets (counts matter): sum(min counts)/sum(max counts).
    ca, cb = Counter(a), Counter(b)
    if not ca and not cb:
        return 1.0
    inter = sum((ca & cb).values())
    union = sum((ca | cb).values())
    return inter / union

# (1 = identical, 0 = completely different goes from 0 to 1)
print(jaccard_sets([1,2,3], [2,3,4]))          # -> 0.5
print(jaccard_tokens("The quick brown fox", "the quick fox jumps"))  # -> 0.6
print(jaccard_multiset([1,1,2], [1,2,2]))      # -> mincounts = 2 (1 once, 2 once)/maxcounts = 4 -> 0.5

