import re

container = list()
f = open('zhuanli.txt', 'r')
fout = open('zhuanli_sorted.txt', 'w')

def smooth(a):
    n = 9 - len(a)
    if n == 0:
        return a
    res = ''
    for i in xrange(0, 4):
        res += a[i]
    if a[5] == '.':
        n -= 1
        res += '0'
        res += a[4]
        res += a[5]
        if n == 0:
            res += a[6]
            res += a[7]
        else:
            res += '0'
            res += a[6]
    else:
        res += a[4]
        res += a[5]
        res += a[6]
        res += '0'
        res += a[7]
    return res

for line in f.readlines():
    if len(line) > 0:
#        print line
        model = '\d\d\d\.\d?\d.\d\d?'
        for i in re.findall(model, line):
#            print i
            container.append((smooth(i), line))
ans = sorted(container, key=lambda pair: pair[0], reverse=False)

counter = 1
for i in ans:
#    print i
    print >> fout, str(counter) + ' ' + i[1]
    counter += 1
f.close()
fout.close()