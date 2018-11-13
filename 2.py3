import sys



def get_word_core(word):
    word = word.lower()
    word_core = ''
    for c in word:
        if c >= 'a' and c <= 'z':
            word_core += c
    return word_core

def is_transpose(wc1, wc2):
    for i in range(len(wc1) - 1):
        tmp = ""
        for j in range(len(wc1)):
            if j == i:
                tmp += wc1[i + 1]
            elif j == i + 1:
                tmp += wc1[i]
            else:
                tmp += wc1[j]
        if tmp == wc2:
            return True
    return False

def are_similar(wc1, wc2):
    if len(wc1) > len(wc2):
        tmp = wc1
        wc1 = wc2
        wc2 = tmp

    if len(wc1) == len(wc2):
        # Transpose
        if is_transpose(wc1, wc2):
            return True
        # Replace
        diffs = 0
        for i in range(len(wc1)):
            if wc1[i] != wc2[i]:
                diffs += 1
        if diffs <= 1:
            return True
        return False
    elif len(wc1) + 1 == len(wc2):
        for i in range(len(wc2)):
            tmp = wc2[:i] + wc2[i + 1:]
            if tmp == wc1:
                return True
        return False
    return False

word_cores = set()
for line in sys.stdin():
    line = line.replace('\n', '')
    if line == '***':
        break

    for word in line.split(' '):
        word_core = get_word_core(word)
        if word_core != "":
            word_cores.add(word_core)

word_cores = sorted(list(word_cores))
printed = False
for wc1 in word_cores:
    similar_cores = []
    for wc2 in word_cores:
        if wc2 != wc1 and are_similar(wc1, wc2):
            similar_cores.append(wc2)
    if len(similar_cores) > 0:
        printed = True
        print(f"{wc1}: " + ' '.join(similar_cores))
if not printed:
    print('***')
exit(0)
