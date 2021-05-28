from socket import *
import tqdm
serverName = "127.0.0.1"
serverPort = 12000
clientSocket =socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
SEPERATOR = "----------"
ans = clientSocket.recv(1024)
print(ans.decode())
sentense = input()
while sentense.upper()!="QUIT":

    clientSocket.send(sentense.encode())
    ans = clientSocket.recv(1024)
    print(ans.decode())
    # if sentense.upper().find("DWLD"):
    #     # filename,filesize=ans.decode().split(SEPERATOR)
    #     # progress = tqdm.tqdm(range(filesize), f"Receiving {filename}", unit="B", unit_scale=True, unit_divisor=1024)
    #     list=sentense.split(" ")
    #     filename=list[1]
    #     with open(filename, "wb") as f:
    #         while True:
    #             # read 1024 bytes from the socket (receive)
    #             bytes_read = clientSocket.recv(4096)
    #             if not bytes_read:
    #                 # nothing is received
    #                 # file transmitting is done
    #                 break
    #             # write to the file the bytes we just received
    #             f.write(bytes_read)
    #             # update the progress bar
    # #             progress.update(len(bytes_read))
    sentense = input()



    # print("from tcp server:",ans.decode())

clientSocket.close()
