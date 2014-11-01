import urllib2

def test():
    url = 'http://blog.csdn.net'
    req=urllib2.Request(url)
    req.add_header("User-Agent","Mozilla/4.0 (compatible; MSIE 8.0; Windows NT 6.1; Trident/4.0)")
    file = urllib2.urlopen(req)
    content = file.read()

