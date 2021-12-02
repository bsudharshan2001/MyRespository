import threading
import socket

sck=socket.socket()
host=socket.gethostname()
port=19008

sck.connect((host,port))
sck.send(bytes("-----Client Initiated-----","utf-8"))

print(sck.recv(1024).decode())
ch=input()
if(ch=="1"):
    sck.send(bytes(ch,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)
elif(ch=="2"):
    sck.send(bytes(ch,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)

    dt=input()
    sck.send(bytes(dt,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)

    fid=input()
    sck.send(bytes(fid,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)

    qt=input()
    sck.send(bytes(qt,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)

    ct=input()
    sck.send(bytes(ct,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)

elif(ch=="3"):
    sck.send(bytes(ch,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)

elif(ch=="4"):
    sck.send(bytes(ch,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)

elif(ch=="5"):
    sck.send(bytes(ch,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)
    
    f_id=input()
    sck.send(bytes(f_id,"utf-8"))
    rply=sck.recv(1024).decode()
    print(rply)


sck.close()





