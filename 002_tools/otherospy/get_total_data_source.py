import os
def get_total_data_source(order):
    path = ""
    listfiles = os.listdir()
    f2 = open("_data"  + ".c", "wb")
    f2.write(b"#include \"FRTP_BaseType.h\"\n")
    f2.write(b"#include \"FRTP_Api_if.h\"\n")
    #f2.write(b"#include \"zernike_process.h\"\n")
    #f2.write(b"extern SMEE_UINT32 *zernike_ptr[78];\n")
    #not used

    f2.write(b"PRAGMA_DATA_SECTION(zernike_data")

    f2.write(b", \".far:Frtp:Api:SDDR\");\n")

    if order:
        f2.write(b"SMEE_UINT32 zernike_data")
    else:
        f2.write(b"int zernike_data")

    f2.write(b"[] ={\n")

    for filenumber in range(len(listfiles)):
        filename = listfiles[filenumber]

        filenamelist = filename.split(sep=".")
        if filenamelist[-1] == "txt":
            f = open(path+filename,"rb")
            linelist = f.readlines()
            # print(linelist)
            #f2 = open(path+filenamelist[0]+"_data"+".txt", "wb")
            #f2 = open("_data"+".txt", "wb")
            # frontfile = filenamelist[0].split(sep="_")

            # n = frontfile[-1]
            # nb=bytes(n,encoding="utf8")
            f2.write(b"{")


            for i in range(len(linelist)):

                f2.write(linelist[i])
                if i!= (len(linelist)-1):
                    f2.write(b",")
            f2.write(b"}\n")
            if filenumber != (len(listfiles) - 1):
                f2.write(b",")

            # f2.write(b"zernike_ptr[")
            # f2.write(nb)
            # f2.write(b"-1]=zernike")
            # f2.write(nb)
            # f2.write(b";\n")


            f.close()
    f2.write(b";")
    f2.close()
