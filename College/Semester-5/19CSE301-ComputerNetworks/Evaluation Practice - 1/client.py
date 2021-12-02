import socket
import threading 
import random
import string
import pandas as pd 
import numpy as np




SERVER= socket.gethostname()
PORT=9999

client=socket.socket(socket.AF_INET,socket.SOCK_STREAM)

print("[CLIENT] Waiting for connection")
try:
    client.connect((SERVER,PORT))
except socket.error as e:
    print(str(e))

wel = client.recv(1024).decode('utf-8')
print(wel)

while True:
    fc = input()
    canContinue = True
    
    if(fc == "I"):
        fc=fc.encode('utf-8')
        client.send(fc) 
        date = client.recv(1024).decode('utf-8')
        print(date)
        cdate = input()
        cdate = cdate.encode('utf-8')
        client.send(cdate)
        
        pid = client.recv(1024).decode('utf-8')
        print(pid)
        cpid = input()
        cpid = cpid.encode('utf-8')
        client.send(cpid)
        
        q = client.recv(1024).decode('utf-8')
        print(q)
        cq = input()
        cq = cq.encode('utf-8')
        client.send(cq)
        
        cost = client.recv(1024).decode('utf-8')
        print(cost)
        ccost = input()
        ccost = ccost.encode('utf-8')
        client.send(ccost)

        '''pid = input("Id : ")
        q = int(input("Quantity : "))
        cost = int(input("Cost : "))
        cl = [fc,date,pid,q,cost,'']
        client.send(x.encode('utf-8') for x in cl)'''
    elif(fc == "M"):
        pid = input("Id : ")
        q = int(input("Quantity : "))
        cost = int(input("Cost : "))
        cl = [fc,pid,q,cost,'']
        client.send(bytes(cl,'utf-8'))
    elif(fc == "V"):
        cl = ["V"]
        client.send(bytes(cl,'utf-8'))
    elif(fc == "U"):
        cl = ["U"]
        client.send(bytes(cl,'utf-8'))
    else:
        canContinue = False
        print("Wrong Input")

client.close()