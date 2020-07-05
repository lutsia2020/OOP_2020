import socket
import threading

class server:
    def __init__(self, port, accept_length=5):
        self.internal_socket = socket.socket()
        self.host = socket.gethostname()
        self.port = port
        self.internal_socket.bind((self.host, self.port))
        self.accept_length = accept_length
        self.tasks = range(1000000000000)
        self.current_item = 0

    def _start_listening_(self):
        self.internal_socket.listen(self.accept_length)

    def _main_job_(self):
        self._start_listening_()
        while True:
            c, addr = self.internal_socket.accept()
            print(f'Got connection from {addr}')
            c.send(str(self.tasks[self.current_item]).encode('utf-8'))
            print('Steps: ' + c.recv(1024).decode('utf-8'))
            self.current_item += 1
            c.close()

    def start_main(self):
        thr = threading.Thread(target=self._main_job_)
        thr.start()

if __name__ == '__OOP_fourth_lab_server__':
    serv = server(8889)
    serv.start_main()
