from sys import stdout
import time
lines = []

with open('../log/gokart_log.txt') as f:
    for line in f.readlines():
        lines.append(line.replace('\n', ''))

i = 0
length = len(lines)
while True:
    print lines[i%length]
    stdout.flush()
    time.sleep(0.03)
    i += 1
    
