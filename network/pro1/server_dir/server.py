from socket import *
import os
# import socket
import tqdm
import ftplib
from pprint import pprint
# def helpFunc():
#     print("Welcome to the FTP client\n\n")
#     print("Call one of the following functions:")
#     print("HELP            :show this help")
#     print("LIST            :list files")
#     print("PWD             :show current directory")
#     print("CD dir_name     :change directory")
#     print("DWLD file_path  :download file")
#     print("QUIT            :exit")
help_Str= "\nCall one of the following functions:\nHELP            :show this help\nLIST            :list files\nPWD             :show current directory\nDWLD file_path  :download file\nQUIT            :exit"
serverName = "127.0.0.1"
serverPort  = 12000
SEPERATOR = "            "
serverSocket =socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(5)
connectionSocket, addr = serverSocket.accept()
# connectionSocket.send(help_Str.encode())
connectionSocket.send("Welcome to the FTP client\n".encode())
# connectionSocket.send(help_Str.encode())
sentense = connectionSocket.recv(1024).decode()
while sentense.upper()!="QUIT":
    # connectionSocket, addr = serverSocket.accept()

    if sentense.upper()=="HELP":
        connectionSocket.send(help_Str.encode())
    elif sentense.upper()=="LIST":
        dirlist = os.listdir(os.getcwd())
        dirlist2=[]
        for obj in dirlist:
            objsize = os.path.getsize(obj)
            dirlist2.append(f"{obj}{SEPERATOR}{objsize}{' bytes'}")
        # dir_str=str(dirlist).strip('[]')
        connectionSocket.send(('\n'.join(dirlist2)).encode())
    elif sentense.upper()=="PWD":
        connectionSocket.send( os.getcwd().encode())
    elif sentense.upper().startswith('CD'):
        list = sentense.split(" ")
        dir_to_cd=list[1]
        os.chdir(dir_to_cd)
        connectionSocket.send( os.getcwd().encode())
    elif sentense.upper().startswith('DWLD'):
        list=sentense.split(" ")
        file_to_dwld=list[1]
        dirlist = os.listdir(os.getcwd())
        dir_str = str(dirlist).strip('[]')
        if not dir_str.find(file_to_dwld):
            connectionSocket.send(("file not found!").encode())
        else:
            filesize = os.path.getsize(file_to_dwld)
    #         # s = socket.socket()
    #         # s.connect((host, port))
    #         SEPERATOR = "----------"
    #         connectionSocket.send(f"{file_to_dwld}{SEPERATOR}{filesize}".encode())
    #         progress = tqdm.tqdm(range(filesize), f"Sending {file_to_dwld}", unit="B", unit_scale=True, unit_divisor=1024)
            with open(file_to_dwld, "rb") as f:
                while True:
                    # read the bytes from the file
                    bytes_read = f.read(4096)
                    if not bytes_read:
                        # file transmitting is done
                        break
                    # we use sendall to assure transimission in
                    # busy networks
                    connectionSocket.sendall(bytes_read)
                    # update the progress bar
    #                 progress.update(len(bytes_read))
    #
    #         # ftp_server = ftplib.FTP(addr)
    #         # with open(file_to_dwld,"wb") as file:
    #         #     connectionSocket.retrbinary(f"RETR {file_to_dwld}", file.write)
    elif sentense.upper()=="QUIT":
        connectionSocket.send("Exiting the server".encode())
        connectionSocket.close()
    # else:
    #     connectionSocket.send("command not found".encode())
    sentense = connectionSocket.recv(1024).decode()
