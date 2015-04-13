prog = raw_input()

for c in prog:
    if c == 'H':
        print 'Hello, World!'
    elif c == 'Q':
        print prog
    elif c == '9':
        for t in xrange(99):
            i = 99 - t
            bottle = "bottle"
            if i > 1:
                bottle += 's'
            print "{} {} of beer on the wall,".format(i, bottle)
            print "{} {} of beer.".format(i, bottle)
            print "Take one down, pass it around,"
            if i == 1:
                print "No bottles of beer on the wall."
            elif i == 2:
                print "1 bottle of beer on the wall."
            else:
                print "{} bottles of beer on the wall.".format(i-1)

            if i > 1:
                print ''
    else:
        pass
