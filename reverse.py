import sys
def reverseStringWords(strToReverse):
    print "here's the string2 \n" + (strToReverse)
    l = list(strToReverse)
    #print l
    
    retStr = ''
    #print 'len of ' + strToReverse + ' is ' + '%d'%len(strToReverse)
    #print 'split '
    words = strToReverse.split()
    #print 'words:'
    #print words
    for j in words:
        #print 'word: ' + j
        str = ''
        l = list(j)
        #print 'l = list(j)'
        #print l
        for k in reversed (range(len(l))):
           str += ('%c'%l[k])
        #print 'str ' + str
        retStr += str + ' '
    return retStr

def reverseString(strToReverse):
  print "here's the string1 \n" + (strToReverse)
  l = list(strToReverse)
  #print 'list1'
  #print l

  j = len(l)
  str = ''
  for k in reversed(range (len(l))):
      str += ('%c'%l[k])
  return str

if __name__ == '__main__':
    testString = 'This is a slightly bigger string  hello again'
    #test=reverseString('hello again')
    test=reverseString(testString)
    print 'reverseString returned'
    print test
    retest=reverseStringWords(test)
    print 'reverseStringWords returned' 
    print retest

