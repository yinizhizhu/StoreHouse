import urllib2
opener = urllib2.build_opener()
opener.addheaders.append(('Cookie', '...'))
f = opener.open("http://pt.hit.edu.cn/take_signin_bonus.php")
print f