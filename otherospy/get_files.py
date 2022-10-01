# coding=utf-8
import urllib.request
import requests
import re
import os


def get_file(url):
    '''
    �ݹ�������վ���ļ�
    :param url:
    :return:
    '''
    if isFile(url):
        print(url)
        try:
            download(url)
        except:
            pass
    else:
        urls = get_url(url)
        for u in urls:
            get_file(u)


def isFile(url):
    '''
    �ж�һ�������Ƿ����ļ�
    :param url:
    :return:
    '''
    if url.endswith('/'):
        return False
    else:
        return True


def download(url):
    '''
    :param url:�ļ�����
    :return: �����ļ����Զ�����Ŀ¼
    '''
    full_name = url.split('//')[-1]
    filename = full_name.split('/')[-1]
    dirname = "/".join(full_name.split('/')[:-1])
    if os.path.exists(dirname):
        pass
    else:
        os.makedirs(dirname, exist_ok=True)
    urllib.request.urlretrieve(url, full_name)


def get_url(base_url):
    '''
    :param base_url:����һ����ַ
    :return: ��ȡ������ַ�е���������
    '''
    text = ''
    try:
        text = requests.get(base_url).text
    except Exception as e:
        print("error - > ", base_url, e)
        pass
    reg = '<a href="(.*)">.*</a>'
    urls = [base_url + url for url in re.findall(reg, text) if url != '../']
    return urls


if __name__ == '__main__':
    get_file('http://www.cs.cmu.edu/afs/cs/academic/class/15213-f15/www/schedule.html')
