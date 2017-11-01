i = 0
f = open('log.log','w')
while True:
    f.write(str(i) + '\n')
    # f.close()
    print(i)
    i=i+1