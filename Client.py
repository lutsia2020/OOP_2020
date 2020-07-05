import socket
from functools import reduce

class client:
    def __init__(self, port):
        self.internal_socket = socket.socket()
        self.host = socket.gethostname()
        self.port = port

    def receive_response(self):
        self.internal_socket = socket.socket()
        self.internal_socket.connect((self.host, self.port))
        num = self.internal_socket.recv(1024).decode('utf-8')
        print(f'Addr: {self.internal_socket.getsockname()} \t Got num: ' + num)
        self.internal_socket.send(str(Client.multiplication_persistence(num)).encode('utf-8'))
        self.internal_socket.close()

    @staticmethod
    def multiplication_persistence(num):
        n = list(num)
        steps = 0
        while len(n) > 1:
            n = list(str(reduce(lambda x, y: int(x) * int(y), n)))
            steps += 1
        return steps

if __name__ == '__OOP_fourth_lab_server__':
    c = client(8889)
    c.receive_response()
