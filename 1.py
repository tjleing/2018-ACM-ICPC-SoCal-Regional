import sys
from collections import defaultdict

index = set()
backup_map = defaultdict(list)

indices = True

for line in sys.stdin:
    line = line.replace('\n', '')
    if line == '':
        indices = False
        continue
    if indices:
        index.add(line)
    else:
        found = 0
        ind = -1
        for i in range(len(line) - 1, -1, -1):
            if line[i] == '_':
                found += 1
            if found == 2:
                ind = i
                break

        backup_map[line[:ind]].append(line)

made_output = False

files_to_print = []
for key in backup_map:
    if key not in index:
        for file in backup_map[key]:
            files_to_print.append(file)

for file in sorted(files_to_print):
    made_output = True
    print('F', file)

files_to_print = []
for file in index:
    if file not in backup_map:
        files_to_print.append(file)

for file in sorted(files_to_print):
    made_output = True
    print('I', file)

if not made_output:
    print('No mismatches.')

exit(0)
