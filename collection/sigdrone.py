#coding=utf-8

import os
import os.path #文件夹遍历函数

#获取目标文件夹的路径
filedir = '/Applications/MAMP/htdocs/externalblue/sigdrone/Scores_By_User'
#获取当前文件夹中的文件名称列表
filenames=os.listdir(filedir)
print(filenames)
#打开当前目录下的result.txt文件，如果没有则创建
f=open('sigdrone.txt','w')
#先遍历文件名
for filename in filenames:
    filepath = filedir+'/'+filename
    #遍历单个文件，读取行数
    if filepath.endswith(".txt"):
        for line in open(filepath):
            f.writelines(line)
        f.write('\nhahaha\n')
#关闭文件
f.close()