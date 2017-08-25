import re

container = list()
f = open('huiyi.txt', 'r')
fout = open('huiyi_sorted.txt', 'w')

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

def getN(a):
    n = len(a)
    for i in xrange(0, n):
        if a[i] == '-':
            return i

for line in f.readlines():
    if len(line) > 3:
#        print line
        model = '.\d?\d.\d?\d-\d\d\d\d'
        for i in re.findall(model, line):
#            print i
            tmp = ''
            head = getN(i)
            for j in xrange(head+1, len(i)):
                tmp += i[j]
            for j in xrange(0, head):
                tmp += i[j]
#            print tmp
            container.append((smooth(tmp), line))
ans = sorted(container, key=lambda pair: pair[0], reverse=False)

counter = 1
for i in ans:
    print >> fout, str(counter) + ' ' + i[1]
    counter += 1
f.close()
fout.close()