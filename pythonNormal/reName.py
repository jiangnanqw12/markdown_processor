import os
#path = "/mnt/c/Users/shadow/Downloads/test"

path = "C:\\BaiduNetdiskDownload\\TV�� 153��"
# ��ȡ��Ŀ¼�������ļ��������б���
f = os.listdir(path)

n = 0

for i in range(len(f)):

    # ���þ��ļ���������·��+�ļ�����

    oldname = path+"/"+f[i]
    filename = f[i].split(sep=".")

    # �������ļ���
    # print(file[-1])
    if filename[-1] == "pdf":
        newname = path+"/"+filename[0]+'.mkv'

        # ��osģ���е�rename�������ļ�����
        os.rename(oldname, newname)
        print(oldname, '======>', newname)
