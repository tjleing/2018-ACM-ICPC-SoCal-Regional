import sys

probability = [1.0] * 1000

for line in sys.stdin:
    line = line.replace('\n', '')
    if line == '':
        continue
    line = line.split(' ')
    if len(line) == 2:
        probability[ord(line[0][0])] = float(line[1])
    elif len(line) == 1:
        p = 1.
        for c in line[0]:
            p *= probability[ord(c)]
        print("%.3f" % p)
