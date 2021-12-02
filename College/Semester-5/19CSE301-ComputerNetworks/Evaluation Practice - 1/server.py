from datetime import date, datetime
import socket
import threading 
import random
import string
import pandas as pd 
import numpy as np
import os

SERVER= socket.gethostname()
PORT=9999
server=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
try:
    server.bind((SERVER,PORT))
except socket.error as e:
    print(str(e))

print("[SERVER] listening..")
server.listen(5)

def client_handle(c,addr):
    connected=True
    x=None
    r="Welcome to Server, Enter values I,M,V or U "
    sr=r.encode('utf-8')
    c.send(sr)
    while connected:
        count = 0
        df=pd.read_excel("D:\College\Semester 5\Computer Networking\Evaluation Practice\data2.xlsx")
        cl = c.recv(1024).decode('utf-8')
        print(cl)
        for i in df.index:
            count += 1
        #ch = cl[0]
        if(cl == "I"):
            toc = "Enter Date: "
            toc = toc.encode('utf-8')
            c.send(toc)
            date = c.recv(1024).decode('utf-8')
            df['date'][count + 1] = date
            
            toc = "Enter Product Id: "
            toc = toc.encode('utf-8')
            c.send(toc)
            pid = c.recv(1024).decode('utf-8')
            df['productid'][count + 1] = pid
            
            toc = "Enter Quantity: "
            toc = toc.encode('utf-8')
            c.send(toc)
            q = c.recv(1024).decode('utf-8')
            df['quantity'][count + 1] = q

            toc = "Enter Cost: "
            toc = toc.encode('utf-8')
            c.send(toc)
            cost = c.recv(1024).decode('utf-8')
            df['cost'][count + 1] = cost
            
            count += 1
            df.to_excel('D:\College\Semester 5\Computer Networking\Evaluation Practice\data2.xlsx',index=False)
        elif(cl == "M"):
            for i in range(len(df.index)):
                if(cl[1] == df['productid'][i]):
                    x = int(df['cost'][i])
                    y = int(df['quantity'][i])
                    df['totalcost'][i] = x*y
            df.to_csv('data.xlsx',index = False)
        elif(cl == "V"):
            l = []
            for i in range(len(df.index)):
                x = df['date'][i]
                y = df['productid'][i]
                z = df['quantity'][i]
                a = df['cost'][i]
                print(x," , ",y," , ",z," , ",a)
        elif(cl == "U"):
            for i in range(10):
                if(df['totalcost'][i]< 1000):
                    df['category'][i] = "A"
                else:
                    df['category'][i] = "B"
            df.to_csv('data.xlsx',index = False)
        if not cl:
            break
    c.close()
while True:
    c,addr = server.accept()
    client_handle(c,addr)
    print("[SERVER] Starting !")
server.close()