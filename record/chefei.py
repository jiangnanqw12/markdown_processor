x = 20


def get_fee(x):

    data = 14+12*2.4+(x-15)*2.4*1.5
    print(data)
    data2 = 14+12*2.4*1.3+(x-15)*2.4*1.5*1.3
    #data2 = 16+12*3.1+(x-15)*4.7
    print(data2)


get_fee(20)
get_fee(50)
