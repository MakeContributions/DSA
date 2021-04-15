def word_count(s: str) -> int:
    return len(s.lower().split())


def unique_word_count(s: str) -> int:
    return len(set(s.lower().split()))
  

for s in ("The Matrix", "To Be or Not to Be", "Kiss Kiss Bang Bang"):
    print(s, word_count(s), unique_word_count(s))
